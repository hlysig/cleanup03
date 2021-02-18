#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>

#include "MADS.pb.h"
#include "MADS.grpc.pb.h"
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

using namespace MADS;
using namespace ObjectCube;
using namespace grpc;

class MADS_ServiceImpl final : public MADS_Service::Service
{
private:
  ObjectCube::Hub *hub;
  Converter *converter;

public:
  MADS_ServiceImpl(ObjectCube::Hub *_hub, Converter *_converter) {
    hub = _hub;
    converter = _converter;
  }

  // == Objects

  Status getObject(ServerContext* context,
                   const GetObjectRequest* request,
                   GetObjectResponse* reply) override {
    try {
      const ObjectCube::Object object = ObjectCube::Object::fetch(request->id());
      reply->set_allocated_object(converter->ObjectToProto(&object));
      return Status::OK;
    }

    catch (...) {
      DebugInfo::getDebugInfo()->output( "MADS_ServiceImpl", "getObject",
                                         "Error retrieving Object: id = " + std::to_string(request->id()));
      std::string msg("Invalid Object identifier");
      return Status(StatusCode::INVALID_ARGUMENT, msg);}
  }

  Status createObject(ServerContext* context,
                      const CreateObjectRequest* request,
                      CreateObjectResponse* reply) override {
    try {
      // Set the input parameters
      ObjectCube::Object object;
      object.setName(request->uri());
      object.setFileType(request->filetype());

      // Create and return
      reply->set_allocated_object(converter->ObjectToProto(&(object.create())));
      return Status::OK;
    }

    catch (...) {
      DebugInfo::getDebugInfo()->output( "MADS_ServiceImpl", "createObject",
                                         "Error creating object: URI  = " + request->uri() + " " +
                                         "Type = " + request->filetype());
      std::string msg("Invalid Object inputs");
      return Status(StatusCode::INVALID_ARGUMENT, msg);
    }
  }

  Status getTagSets(ServerContext* context,
                    const GetTagSetsRequest* request,
                    GetTagSetsResponse* reply) override {
    try {
      const vector<ObjectCube::TagSet *>tagsets = hub->getTagSets();
      for (auto tagset = tagsets.begin(); tagset != tagsets.end(); ++tagset) {
        converter->TagSetToProto(*tagset, reply->add_tagsets());
      }
      return Status::OK;
    }

    catch (...) {
      DebugInfo::getDebugInfo()->output( "MADS_ServiceImpl", "getTagSets",
                                         "Unknown error ");
      std::string msg("Error getting tagset");
      return Status(StatusCode::NOT_FOUND, msg);
    }
  }

  Status getTagSet(ServerContext* context,
                   const GetTagSetRequest* request,
                   GetTagSetResponse* reply) override {
    try {
      const ObjectCube::TagSet *tagset = hub->getTagSet(request->id());
      reply->set_allocated_tagset(converter->TagSetToProto(tagset));
      return Status::OK;
    }

    catch (...) {
      DebugInfo::getDebugInfo()->output( "MADS_ServiceImpl", "getTagSet",
                                         "Error retrieving TagSet: id = " + std::to_string(request->id()));
      std::string msg("Invalid TagSet identifier");
      return Status(StatusCode::INVALID_ARGUMENT, msg);
    }
  }

  Status createTagSet(ServerContext* context,
                      const CreateTagSetRequest* request,
                      CreateTagSetResponse* reply) override {
    ObjectCube::TagSet *tagset;
    DebugInfo::getDebugInfo()->output( "MADS_ServiceImpl", "createTagSet",
                                       "name = " + request->name() +
                                       " desc = " + request->description() +
                                       " type = " + std::to_string(request->type()));

    switch (request->type()) {
    case MADS::TagSetType::ALPHANUMERICAL:
      DebugInfo::getDebugInfo()->output( "MADS_ServiceImpl", "createTagSet", "Alpha");
      tagset = new ObjectCube::AlphanumericalTagSet(request->name(), request->description());
      break;
    case MADS::TagSetType::NUMERICAL:
      DebugInfo::getDebugInfo()->output( "MADS_ServiceImpl", "createTagSet", "Numer");
      tagset = new ObjectCube::NumericalTagSet(request->name(), request->description());
      break;
    case MADS::TagSetType::DATE:
      DebugInfo::getDebugInfo()->output( "MADS_ServiceImpl", "createTagSet", "Date");
      tagset = new ObjectCube::DateTagSet(request->name(), request->description());
      break;
    case MADS::TagSetType::TIME:
      DebugInfo::getDebugInfo()->output( "MADS_ServiceImpl", "createTagSet", "Time");
      tagset = new ObjectCube::TimeTagSet(request->name(), request->description());
      break;
    case MADS::TagSetType::RGB:
      DebugInfo::getDebugInfo()->output( "MADS_ServiceImpl", "createTagSet", "RGB");
      tagset = new ObjectCube::RGBTagSet(request->name(), request->description());
      break;
    default:
      std::string msg("No value given for tag");
      return Status(StatusCode::INVALID_ARGUMENT, msg);
    }
    reply->set_allocated_tagset(converter->TagSetToProto(tagset->create()));

    return Status::OK;
  }

  Status getTags(ServerContext* context,
                 const GetTagsRequest* request,
                 GetTagsResponse* reply) override {
    const vector<ObjectCube::Tag *>tags = hub->getAllTags();
    for (auto tag = tags.begin(); tag != tags.end(); ++tag) {
      MADS::Tag* protoTag = reply->add_tags();
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

  Status createOrGetTag(ServerContext* context,
                        const CreateTagRequest* request,
                        CreateTagResponse* reply) override {
    ObjectCube::TagSet *tagSet = hub->getTagSet(request->tagsetid());
    const ObjectCube::Tag *tag;
    if (request->has_alphanumerical()) {
      tag = tagSet->fetchOrAddTag(request->alphanumerical().value());
    } else if (request->has_numerical()) {
      tag = tagSet->fetchOrAddTag(request->numerical().value());
    } else if (request->has_date()) {
      tag = tagSet->fetchOrAddTag(request->date().value());
    } else if (request->has_time()) {
      tag = tagSet->fetchOrAddTag(request->time().value());
    } else if (request->has_rgb()) {
      std::string msg("Creating RGB tags not implemented");
      return Status(StatusCode::INVALID_ARGUMENT, msg);
    } else {
      std::string msg("No value given for tag");
      return Status(StatusCode::INVALID_ARGUMENT, msg);
    }
    reply->set_allocated_tag(converter->TagToProto(tag));
    return Status::OK;
  }

  Status createTagging(ServerContext* context,
                       const CreateTaggingRequest* request,
                       CreateTaggingResponse* reply) override {
    ObjectCube::Object object = ObjectCube::Object::fetch(request->objectid());
    const ObjectCube::Tag *tag = hub->getTag(request->tagid());
    ObjectCube::ObjectTag objecttag(tag);
    object.addTag(objecttag);

    reply->set_allocated_tagging(converter->ObjectTagToProto(&objecttag));
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
  MADS_ServiceImpl service(hub, converter);

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
