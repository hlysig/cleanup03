#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>

#include "../proto/OC.pb.h"
#include "../proto/OC.grpc.pb.h"
#include "convert.h"

using namespace OC;
using namespace grpc;

class OCServiceImpl final : public OCService::Service
{
public:
  //Hub *hub;
  //OCServiceImpl(Hub *_hub) { hub = _hub; }
  OCServiceImpl() {};
  
  Status getTag(ServerContext* context,
		const GetTagRequest* request,
		GetTagResponse* reply) override {
    //Tag *tag = this->hub.getTag(request->id);
    ObjectCube::Tag *tag = new ObjectCube::Tag(request->id(), 2, 3, "Hello!");
    reply->set_allocated_tag(convert::TagToProto(tag));
    return Status::OK;
  }
};


void RunServer() {
  std::string server_address("0.0.0.0:26026");
  OCServiceImpl service;

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
