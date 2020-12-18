#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>

#include "OC.pb.h"
#include "OC.grpc.pb.h"
#include "convert.h"

#include "../core/Hub.h"


using namespace OC;
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
