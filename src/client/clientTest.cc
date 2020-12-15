#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>
#include "OC.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using OC::OCService;

class OCTestClient {
public:
  OCTestClient(std::shared_ptr<Channel> channel)
    : stub_(OCService::NewStub(channel)) {}

  void runCommands() {
    Status status;
    std::string helpstring = "Supported commands: tag <id>, stop, help";
    std::cout << helpstring << std::endl;
    std::cout << "# ";
    std::string input;

    while (std::cin >> input) {
      if (input == "tag") {
	int id;
	std::cin >> id;

	OC::GetTagRequest request;
	request.set_id(id);

	OC::GetTagResponse *reply = new OC::GetTagResponse();
	ClientContext context;
	status = stub_->getTag(&context, request, reply);

	if (status.ok())
	  std::cout << "Received: "
		    << reply->tag().id() << ", " << reply->tag().tagsetid()
		    << std::endl;
      } else if (input == "tagset") {
	std::cout << "Not yet implemented" << std::endl;
      } else if (input == "reconnect") {
	std::cout << "Not yet implemented" << std::endl;
      } else if (input == "stop") {
	OC::Empty request;
	OC::Empty *reply = new OC::Empty();
	ClientContext context;
	status = stub_->stopService(&context, request, reply);
	return;
      } else if (input == "help") {
	std::cout << helpstring << std::endl;
      } else if (input == "exit") {
	return;
      } else {
	std::cout << "Unknown command: " << input << std::endl;
      }

      if (!status.ok()) {
	std::cout << status.error_code() << ": " << status.error_message() << std::endl;
      }
      std::cout << "# ";
    }
  }
  
private:
  std::unique_ptr<OCService::Stub> stub_;
};

int main(int argc, char** argv) {
  std::string target_str = "localhost:26026";
  OCTestClient tester(grpc::CreateChannel(target_str, grpc::InsecureChannelCredentials()));

  tester.runCommands();
  return 0;
}
