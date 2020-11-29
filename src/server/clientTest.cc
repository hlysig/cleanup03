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

  // Assembles the client's payload, sends it and presents the response back from the server.
  OC::GetTagResponse *GetTag(const int id) {
    // Data we are sending to the server.
    OC::GetTagRequest request;
    request.set_id(id);

    // Container for the data we expect from the server.
    OC::GetTagResponse *reply = new OC::GetTagResponse();

    // Context for the client. It could be used to convey extra information to
    // the server and/or tweak certain RPC behaviors.
    ClientContext context;

    // The actual RPC.
    Status status = stub_->getTag(&context, request, reply);

    // Act upon its status.
    if (status.ok()) {
      return reply;
    } else {
      std::cout << status.error_code() << ": " << status.error_message()
                << std::endl;
      exit(0);
    }
  }

  // Assembles the client's payload, sends it and presents the response back from the server.
  void ReConnectDB() {
    // Data we are sending to the server.
    OC::Empty request;

    // Container for the data we expect from the server.
    OC::Empty *reply = new OC::Empty();

    // Context for the client. It could be used to convey extra information to
    // the server and/or tweak certain RPC behaviors.
    ClientContext context;

    // The actual RPC.
    Status status = stub_->reConnectDB(&context, request, reply);

      // Act upon its status.
    if (status.ok()) {
      return;
    } else {
      std::cout << status.error_code() << ": " << status.error_message() << std::endl;
      exit(0);
    }
  }

  // Assembles the client's payload, sends it and presents the response back from the server.
  void StopService() {
    // Data we are sending to the server.
    OC::Empty request;

    // Container for the data we expect from the server.
    OC::Empty *reply = new OC::Empty();

    // Context for the client. It could be used to convey extra information to
    // the server and/or tweak certain RPC behaviors.
    ClientContext context;

    // The actual RPC.
    Status status = stub_->stopService(&context, request, reply);

    // Should get an error back, we can ignore it
    return;
  }
  
  private:
  std::unique_ptr<OCService::Stub> stub_;
};

int main(int argc, char** argv) {
  // Instantiate the client. It requires a channel, out of which the actual RPCs
  // are created. This channel models a connection to an endpoint specified by
  // the argument "--target=" which is the only expected argument.
  // We indicate that the channel isn't authenticated (use of
  // InsecureChannelCredentials()).
  std::string target_str = "localhost:26026";
  OCTestClient tester(grpc::CreateChannel(
      target_str, grpc::InsecureChannelCredentials()));

  std::string input;
  while (std::cin >> input) {
    if (input == "tag") {
      int id;
      std::cin >> id;
      OC::GetTagResponse *reply = tester.GetTag(id);
      std::cout << "Received: "
		<< reply->tag().id() << ", " << reply->tag().tagsetid()
		<< std::endl;
    } else if (input == "tagset") {
      //      int id;
      //      cin >> id;
      //      OC::GetTagSetResponse *reply = tester.GetTagSet(id);
      //      std::cout << "Received: "
      //		<< reply->tagSet().id() << ", " << reply->tagSet().tagsetid()
      //		<< std::endl;
      std::cout << "Not yet implemented" << std::endl;
    } else if (input == "reconnect") {
      tester.ReConnectDB();
    } else if (input == "stop") {
      tester.StopService();
      return 0;
    } else if (input == "exit") {
      return 0;
    } else {
      std::cout << "Unknown command: " << input << std::endl;
    }
  }

  return 0;
}
