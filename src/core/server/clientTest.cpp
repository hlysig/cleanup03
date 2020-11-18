#include <iostream>
#include <memory>
#include <string>

class OCTestClient {
public:
  OCTestClient(std::shared_ptr<Channel> channel)
      : stub_(Service::NewStub(channel)) {}

  // Assembles the client's payload, sends it and presents the response back
  // from the server.
  std::string GetTag(const int id) {
    // Data we are sending to the server.
    GetTagRequest request;
    request.set_id(id);

    // Container for the data we expect from the server.
    GetTagResponse reply;

    // Context for the client. It could be used to convey extra information to
    // the server and/or tweak certain RPC behaviors.
    ClientContext context;

    // The actual RPC.
    Status status = stub_->GetTag(&context, request, &reply);

    // Act upon its status.
    if (status.ok()) {
      return reply.name();
    } else {
      std::cout << status.error_code() << ": " << status.error_message()
                << std::endl;
      return "RPC failed";
    }
  }
};

int main(int argc, char** argv) {
  // Instantiate the client. It requires a channel, out of which the actual RPCs
  // are created. This channel models a connection to an endpoint specified by
  // the argument "--target=" which is the only expected argument.
  // We indicate that the channel isn't authenticated (use of
  // InsecureChannelCredentials()).
  std::string target_str;
  std::string arg_str("--target");
  if (argc > 1) {
    std::string arg_val = argv[1];
    size_t start_pos = arg_val.find(arg_str);
    if (start_pos != std::string::npos) {
      start_pos += arg_str.size();
      if (arg_val[start_pos] == '=') {
        target_str = arg_val.substr(start_pos + 1);
      } else {
        std::cout << "The only correct argument syntax is --target=" << std::endl;
        return 0;
      }
    } else {
      std::cout << "The only acceptable argument is --target=" << std::endl;
      return 0;
    }
  } else {
    target_str = "localhost:26026";
  }
  OCTestClient tester(grpc::CreateChannel(
      target_str, grpc::InsecureChannelCredentials()));
  int id = 1;
  std::string reply = tester.GetTag(id);
  std::cout << "Tester received: " << reply << std::endl;

  return 0;
}
