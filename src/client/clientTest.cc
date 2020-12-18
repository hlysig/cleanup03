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
    std::string helpstring = "Supported commands: tagsets, tagset <id>, tags, tag <id>, newtag <name>, stop, help";
    std::cout << helpstring << std::endl;
    std::cout << "# ";
    std::string input;

    while (std::cin >> input) {
      if (input == "tagsets") {
        OC::GetTagSetsRequest request; 

        OC::GetTagSetsResponse *reply = new OC::GetTagSetsResponse();

        ClientContext context;
        status = stub_->getTagSets(&context, request, reply);

        if (status.ok()) {
          std::cout << "GetTagSets rpc succeeded." << std::endl;
          for (int i = 0; i < reply->tagsets_size(); i++) {
            const OC::TagSet& tagset = reply->tagsets(i);
            std::cout << "Id: " << tagset.id() << " Name: " << tagset.name() << std::endl;
          }
        } else {
          std::cout << "GetTagSets rpc failed." << std::endl;
        }
      } else if (input == "tagset") {
          int id;
          std::cin >> id;
          OC::GetTagSetResponse *reply = new OC::GetTagSetResponse();

          OC::GetTagSetRequest request;
          request.set_id(id);

          ClientContext context;
          status = stub_->getTagSet(&context, request, reply);

          if (status.ok())
            std::cout << "Received: "
                      << reply->tagset().id() << ", " << reply->tagset().name()
                      << std::endl;
      } else if (input == "tags") {
        OC::GetTagsRequest request; 

        OC::GetTagsResponse *reply = new OC::GetTagsResponse();

        ClientContext context;
        status = stub_->getTags(&context, request, reply);


        if (status.ok()) {
          std::cout << "GetTagSets rpc succeeded." << std::endl;
          for (int i = 0; i < reply->tags_size(); i++) {
            const OC::Tag& tag = reply->tags(i);
            std::cout << "Id: " << tag.id() << " Name: " << tag.name() << std::endl;
          }
        } else {
          std::cout << "GetTagSets rpc failed." << std::endl;
        }
      } else if (input == "tag") {
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
      } else if (input == "newtag") {
        std::string name;
        std::cin >> name;

        OC::PutTagRequest request;
        request.set_tagsetid(1);
        request.set_name(name);

        OC::PutTagResponse *reply = new OC::PutTagResponse();
        ClientContext context;
        status = stub_->putTag(&context, request, reply);

        if (status.ok())
          std::cout << "Received: "
                    << reply->tag().id() << ", " << reply->tag().tagsetid()
                    << std::endl;
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
