#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>

#include "OC.pb.h"
#include "OC.grpc.pb.h"
#include "convert.h"

#include "../core/Hub.h"
#include "../core/LayerShared/Parameters.h"
#include "../core/LayerShared/DebugInfo.h"
#include "../core/TagSet/TagSet.h"
#include "../core/TagSet/AlphanumericalTagSet.h"
#include "../core/TagSet/NumericalTagSet.h"
#include "../core/TagSet/DateTagSet.h"
#include "../core/TagSet/TimeTagSet.h"
#include "../core/TagSet/RGBTagSet.h"

using namespace OC;
using namespace ObjectCube;
using namespace grpc;

class OCServiceImpl final : public OCService::Service
{
private:
  ObjectCube::Hub *hub;
  Converter *converter;

public:
  OCServiceImpl(ObjectCube::Hub *_hub, Converter *_converter) {
    hub = _hub;
    converter = _converter;
  }

  Status getObject(ServerContext* context,
                   const GetObjectRequest* request,
                   GetObjectResponse* reply) override {
    try {
      const ObjectCube::Object object = ObjectCube::Object::fetch(request->id());
      reply->set_allocated_object(converter->ObjectToProto(&object));
      return Status::OK;
    }
    catch (...) {
      DebugInfo::getDebugInfo()->output( "OCServiceImpl", "getObject",
                                         "Error retrieving object id = " + std::to_string(request->id()));
      std::string msg("Invalid Object identifier");
      return Status(StatusCode::INVALID_ARGUMENT, msg);
    }
  }

  Status putObject(ServerContext* context,
                   const PutObjectRequest* request,
                   PutObjectResponse* reply) override {
    ObjectCube::Object object;
    object.setName(request->name());
    object.setThumbnail(request->thumbnail());
    object.setFileType(request->filetype());
    hub->addObject(object);

    DebugInfo::getDebugInfo()->output( "OCServiceImpl", "putObject",  std::to_string(object.getId()) );
    reply->set_allocated_object(converter->ObjectToProto(&object));
    return Status::OK;
  }

  Status getTagSets(ServerContext* context,
                    const GetTagSetsRequest* request,
                    GetTagSetsResponse* reply) override {
    const vector<ObjectCube::TagSet *>tagsets = hub->getTagSets();
    for (auto tagset = tagsets.begin(); tagset != tagsets.end(); ++tagset) {
      OC::TagSet* protoTagSet = reply->add_tagsets();
      converter->TagSetToProto(*tagset, protoTagSet);
    }
    return Status::OK;
  }

  Status getTagSet(ServerContext* context,
                   const GetTagSetRequest* request,
                   GetTagSetResponse* reply) override {
    const ObjectCube::TagSet *tagset = hub->getTagSet(request->id());
    reply->set_allocated_tagset(converter->TagSetToProto(tagset));
    return Status::OK;
  }

  Status putAlphanumericalTagSet(ServerContext* context,
                                 const PutTagSetRequest* request,
                                 PutTagSetResponse* reply) override {
    ObjectCube::TagSet *tagset = new ObjectCube::AlphanumericalTagSet(request->name(), request->description());
    reply->set_allocated_tagset(converter->TagSetToProto(tagset->create()));
    return Status::OK;
  }

  Status putNumericalTagSet(ServerContext* context,
                            const PutTagSetRequest* request,
                            PutTagSetResponse* reply) override {
    ObjectCube::TagSet *tagset = new ObjectCube::NumericalTagSet(request->name(), request->description());
    reply->set_allocated_tagset(converter->TagSetToProto(tagset->create()));
    return Status::OK;
  }

  Status putDateTagSet(ServerContext* context,
                       const PutTagSetRequest* request,
                       PutTagSetResponse* reply) override {
    ObjectCube::TagSet *tagset = new ObjectCube::DateTagSet(request->name(), request->description());
    reply->set_allocated_tagset(converter->TagSetToProto(tagset->create()));
    return Status::OK;
  }

  Status putTimeTagSet(ServerContext* context,
                       const PutTagSetRequest* request,
                       PutTagSetResponse* reply) override {
    ObjectCube::TagSet *tagset = new ObjectCube::TimeTagSet(request->name(), request->description());
    reply->set_allocated_tagset(converter->TagSetToProto(tagset->create()));
    return Status::OK;
  }

  Status putRGBTagSet(ServerContext* context,
                      const PutTagSetRequest* request,
                      PutTagSetResponse* reply) override {
    ObjectCube::TagSet *tagset = new ObjectCube::RGBTagSet(request->name(), request->description());
    reply->set_allocated_tagset(converter->TagSetToProto(tagset->create()));
    return Status::OK;
  }

  Status getTags(ServerContext* context,
                 const GetTagsRequest* request,
                 GetTagsResponse* reply) override {
    const vector<ObjectCube::Tag *>tags = hub->getAllTags();
    for (auto tag = tags.begin(); tag != tags.end(); ++tag) {
      OC::Tag* protoTag = reply->add_tags();
      converter->TagToProto(*tag, protoTag);
    }
    return Status::OK;
  }

  Status getTag(ServerContext* context,
                const GetTagRequest* request,
                GetTagResponse* reply) override {
    const ObjectCube::Tag *tag = hub->getTag(request->id());
    reply->set_allocated_tag(converter->TagToProto(tag));
    return Status::OK;
  }

  Status putTag(ServerContext* context,
                const PutTagRequest* request,
                PutTagResponse* reply) override {
    ObjectCube::TagSet *tagSet = hub->getTagSet(request->tagsetid());
    const ObjectCube::Tag *tag = tagSet->fetchOrAddTag(request->name());
    reply->set_allocated_tag(converter->TagToProto(tag));
    return Status::OK;
  }

  Status reConnectDB(ServerContext *context,
		     const Empty* request,
		     Empty *reply) override {
    std::cout << "Server reset (not implemented)" << std::endl;
    return Status::OK;
  }

  Status stopService(ServerContext *context,
		     const Empty* request,
		     Empty *reply) override {
    std::cout << "Server halted" << std::endl;
    exit(0);
  }
};

void RunServer() {
  std::string server_address("0.0.0.0:26026");
  ObjectCube::Hub *hub = ObjectCube::Hub::getHub();
  MADS_gRPC_converter *converter = new MADS_gRPC_converter();
  OCServiceImpl service(hub, converter);

  ObjectCube::Parameters::getParameters() -> add("outputDebugInfo", "1");

  grpc::EnableDefaultHealthCheckService(true);
  grpc::reflection::InitProtoReflectionServerBuilderPlugin();
  ServerBuilder builder;
  // Listen on the given address without any authentication mechanism.
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  // Register "service" as the instance through which we'll communicate with
  // clients. In this case it corresponds to an *synchronous* service.
  builder.RegisterService(&service);
  // Finally assemble the server.
  std::unique_ptr<Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;

  // Wait for the server to shudown. Note that some other thread must be
  // responsible for shutting down the server for this call to ever return.
  server->Wait();
}

int main(int argc, char** argv) {
  RunServer();

  return 0;
}
