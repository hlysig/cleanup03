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
public:
  ObjectCube::Hub *hub;
  OCServiceImpl(ObjectCube::Hub *_hub) { hub = _hub; }
  
  Status getTag(ServerContext* context,
		const GetTagRequest* request,
		GetTagResponse* reply) override {
    //Tag *tag = this->hub.getTag(request->id);
    const ObjectCube::Tag *tag = hub->getTag(request->id());
    reply->set_allocated_tag(convert::TagToProto(tag));
    return Status::OK;
  }

  Status reConnectDB(ServerContext *context,
		     const Empty* request,
		     Empty *reply) override {
    delete(hub);
    hub = ObjectCube::Hub::getHub();
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
  std::string server_address("localhost:26026");
  ObjectCube::Hub *hub = ObjectCube::Hub::getHub();
  OCServiceImpl service(hub);

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
