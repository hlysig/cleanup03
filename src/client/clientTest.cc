#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>
#include "MADS.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using MADS::MADS_Service;

class MADSTestClient {
public:
  MADSTestClient(std::shared_ptr<Channel> channel)
    : stub_(MADS_Service::NewStub(channel)) {}

  void runCommands() {
    Status status;
    std::string helpstring = "Supported commands: tagsets, tagset <id>, tags, tag <id>, newtag <name>, stop, help";
    std::cout << helpstring << std::endl;
    std::cout << "# ";
    std::string input;

    while (std::cin >> input) {
      if (input == "tagsets") {
        MADS::GetTagSetsRequest request; 

        MADS::GetTagSetsResponse *reply = new MADS::GetTagSetsResponse();

        ClientContext context;
        status = stub_->getTagSets(&context, request, reply);

        if (status.ok()) {
          std::cout << "GetTagSets rpc succeeded." << std::endl;
          for (int i = 0; i < reply->tagsets_size(); i++) {
            const MADS::TagSet& tagset = reply->tagsets(i);
            std::cout << "Id: " << tagset.id()
                      << " Name: " << tagset.name()
                      << " Description: " << tagset.description()
                      << " Type: " << tagset.type() 
                      << " AccessId: " << tagset.accessid() << std::endl;
          }
        } else {
          std::cout << "GetTagSets rpc failed." << std::endl;
        }
      } else if (input == "tagset") {
          int id;
          std::cin >> id;
          MADS::GetTagSetResponse *reply = new MADS::GetTagSetResponse();

          MADS::GetTagSetRequestById request;
          request.set_id(id);

          ClientContext context;
          status = stub_->getTagSetById(&context, request, reply);

          if (status.ok())
            if (status.ok())
              std::cout << "Received TagSet: "
                        << reply->tagset().id() << ", "
                        << reply->tagset().name() << ", "
                        << reply->tagset().description() << ", "
                        << reply->tagset().type() << ", "
                        << reply->tagset().accessid() <<  std::endl;
      } else if (input == "newtagset") {
        std::string name;
        std::cin >> name;

        std::string type;
        std::cin >> type;

        MADS::CreateTagSetRequest request;
        request.set_name(name);
        request.set_description("description");

        MADS::CreateTagSetResponse *reply = new MADS::CreateTagSetResponse();
        ClientContext context;

        if (type == "Date")
          request.set_type(MADS::TagSetType::DATE);
        else if (type == "Time")
          request.set_type(MADS::TagSetType::TIME);
        else if (type == "Numerical")
          request.set_type(MADS::TagSetType::NUMERICAL);
        else if (type == "RGB")
          request.set_type(MADS::TagSetType::RGB);
        else // including Alphanumerical
          request.set_type(MADS::TagSetType::ALPHANUMERICAL);
        status = stub_->createTagSet(&context, request, reply);

        if (status.ok())
          std::cout << "Received TagSet: "
                    << reply->tagset().id() << ", "
                    << reply->tagset().name() << ", "
                    << reply->tagset().description() << ", "
                    << reply->tagset().type() 
                    << reply->tagset().accessid() <<  std::endl;
      } else if (input == "tags") {
        MADS::GetTagsRequest request; 

        MADS::GetTagsResponse *reply = new MADS::GetTagsResponse();

        ClientContext context;
        status = stub_->getTags(&context, request, reply);

        if (status.ok()) {
          std::cout << "GetTagSets rpc succeeded." << std::endl;
          for (int i = 0; i < reply->tags_size(); i++) {
            const MADS::Tag& tag = reply->tags(i);
            std::cout << "Id: " << tag.id() << std::endl;
          }
        } else {
          std::cout << "GetTagSets rpc failed." << std::endl;
        }
      } else if (input == "tag") {
        int id;
        std::cin >> id;

        MADS::GetTagRequest request;
        request.set_id(id);

        MADS::GetTagResponse *reply = new MADS::GetTagResponse();
        ClientContext context;
        status = stub_->getTag(&context, request, reply);

        if (status.ok())
          std::cout << "Received: "
                    << reply->tag().id() << ", " << reply->tag().tagsetid()
                    << std::endl;
      } else if (input == "object") {
        int id;
        std::cin >> id;

        MADS::GetObjectRequest request;
        request.set_id(id);

        MADS::GetObjectResponse *reply = new MADS::GetObjectResponse();
        ClientContext context;
        status = stub_->getObject(&context, request, reply);

        if (status.ok())
          std::cout << "Received Object: "
                    << reply->object().id() << ", "
                    << reply->object().uri() << ", "
                    << reply->object().thumbnail() << ", "
                    << reply->object().filetype() <<  std::endl;
      } else if (input == "newobject") {
        std::string name;
        std::cin >> name;

        MADS::CreateObjectRequest request;
        request.set_uri(name);
        request.set_filetype("filetype");

        MADS::CreateObjectResponse *reply = new MADS::CreateObjectResponse();
        ClientContext context;
        status = stub_->createObject(&context, request, reply);

        if (status.ok())
          std::cout << "Received Object: "
                    << reply->object().id() << ", "
                    << reply->object().uri() << ", "
                    << reply->object().thumbnail() << ", "
                    << reply->object().filetype() <<  std::endl;
      } else if (input == "reconnect") {
        std::cout << "Not yet implemented" << std::endl;
      } else if (input == "stop") {
        MADS::Empty request;
        MADS::Empty *reply = new MADS::Empty();
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
  std::unique_ptr<MADS_Service::Stub> stub_;
};

int main(int argc, char** argv) {
  std::string target_str = "localhost:26026";
  MADSTestClient tester(grpc::CreateChannel(target_str, grpc::InsecureChannelCredentials()));

  tester.runCommands();
  return 0;
}
