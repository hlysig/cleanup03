// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: MADS.proto

#include "MADS.pb.h"
#include "MADS.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace MADS {

static const char* MADS_Service_method_names[] = {
  "/MADS.MADS_Service/getObject",
  "/MADS.MADS_Service/createObject",
  "/MADS.MADS_Service/getTagSets",
  "/MADS.MADS_Service/getTagSet",
  "/MADS.MADS_Service/createTagSet",
  "/MADS.MADS_Service/getTags",
  "/MADS.MADS_Service/getTag",
  "/MADS.MADS_Service/createOrGetTag",
  "/MADS.MADS_Service/getTaggings",
  "/MADS.MADS_Service/getTagging",
  "/MADS.MADS_Service/createTagging",
  "/MADS.MADS_Service/reConnectDB",
  "/MADS.MADS_Service/stopService",
};

std::unique_ptr< MADS_Service::Stub> MADS_Service::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< MADS_Service::Stub> stub(new MADS_Service::Stub(channel));
  return stub;
}

MADS_Service::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_getObject_(MADS_Service_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_createObject_(MADS_Service_method_names[1], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_getTagSets_(MADS_Service_method_names[2], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_getTagSet_(MADS_Service_method_names[3], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_createTagSet_(MADS_Service_method_names[4], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_getTags_(MADS_Service_method_names[5], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_getTag_(MADS_Service_method_names[6], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_createOrGetTag_(MADS_Service_method_names[7], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_getTaggings_(MADS_Service_method_names[8], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_getTagging_(MADS_Service_method_names[9], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_createTagging_(MADS_Service_method_names[10], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_reConnectDB_(MADS_Service_method_names[11], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_stopService_(MADS_Service_method_names[12], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status MADS_Service::Stub::getObject(::grpc::ClientContext* context, const ::MADS::GetObjectRequest& request, ::MADS::GetObjectResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_getObject_, context, request, response);
}

void MADS_Service::Stub::experimental_async::getObject(::grpc::ClientContext* context, const ::MADS::GetObjectRequest* request, ::MADS::GetObjectResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_getObject_, context, request, response, std::move(f));
}

void MADS_Service::Stub::experimental_async::getObject(::grpc::ClientContext* context, const ::MADS::GetObjectRequest* request, ::MADS::GetObjectResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_getObject_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::MADS::GetObjectResponse>* MADS_Service::Stub::PrepareAsyncgetObjectRaw(::grpc::ClientContext* context, const ::MADS::GetObjectRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::MADS::GetObjectResponse>::Create(channel_.get(), cq, rpcmethod_getObject_, context, request, false);
}

::grpc::ClientAsyncResponseReader< ::MADS::GetObjectResponse>* MADS_Service::Stub::AsyncgetObjectRaw(::grpc::ClientContext* context, const ::MADS::GetObjectRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncgetObjectRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status MADS_Service::Stub::createObject(::grpc::ClientContext* context, const ::MADS::CreateObjectRequest& request, ::MADS::CreateObjectResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_createObject_, context, request, response);
}

void MADS_Service::Stub::experimental_async::createObject(::grpc::ClientContext* context, const ::MADS::CreateObjectRequest* request, ::MADS::CreateObjectResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_createObject_, context, request, response, std::move(f));
}

void MADS_Service::Stub::experimental_async::createObject(::grpc::ClientContext* context, const ::MADS::CreateObjectRequest* request, ::MADS::CreateObjectResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_createObject_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::MADS::CreateObjectResponse>* MADS_Service::Stub::PrepareAsynccreateObjectRaw(::grpc::ClientContext* context, const ::MADS::CreateObjectRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::MADS::CreateObjectResponse>::Create(channel_.get(), cq, rpcmethod_createObject_, context, request, false);
}

::grpc::ClientAsyncResponseReader< ::MADS::CreateObjectResponse>* MADS_Service::Stub::AsynccreateObjectRaw(::grpc::ClientContext* context, const ::MADS::CreateObjectRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsynccreateObjectRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status MADS_Service::Stub::getTagSets(::grpc::ClientContext* context, const ::MADS::GetTagSetsRequest& request, ::MADS::GetTagSetsResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_getTagSets_, context, request, response);
}

void MADS_Service::Stub::experimental_async::getTagSets(::grpc::ClientContext* context, const ::MADS::GetTagSetsRequest* request, ::MADS::GetTagSetsResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_getTagSets_, context, request, response, std::move(f));
}

void MADS_Service::Stub::experimental_async::getTagSets(::grpc::ClientContext* context, const ::MADS::GetTagSetsRequest* request, ::MADS::GetTagSetsResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_getTagSets_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::MADS::GetTagSetsResponse>* MADS_Service::Stub::PrepareAsyncgetTagSetsRaw(::grpc::ClientContext* context, const ::MADS::GetTagSetsRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::MADS::GetTagSetsResponse>::Create(channel_.get(), cq, rpcmethod_getTagSets_, context, request, false);
}

::grpc::ClientAsyncResponseReader< ::MADS::GetTagSetsResponse>* MADS_Service::Stub::AsyncgetTagSetsRaw(::grpc::ClientContext* context, const ::MADS::GetTagSetsRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncgetTagSetsRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status MADS_Service::Stub::getTagSet(::grpc::ClientContext* context, const ::MADS::GetTagSetRequest& request, ::MADS::GetTagSetResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_getTagSet_, context, request, response);
}

void MADS_Service::Stub::experimental_async::getTagSet(::grpc::ClientContext* context, const ::MADS::GetTagSetRequest* request, ::MADS::GetTagSetResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_getTagSet_, context, request, response, std::move(f));
}

void MADS_Service::Stub::experimental_async::getTagSet(::grpc::ClientContext* context, const ::MADS::GetTagSetRequest* request, ::MADS::GetTagSetResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_getTagSet_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::MADS::GetTagSetResponse>* MADS_Service::Stub::PrepareAsyncgetTagSetRaw(::grpc::ClientContext* context, const ::MADS::GetTagSetRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::MADS::GetTagSetResponse>::Create(channel_.get(), cq, rpcmethod_getTagSet_, context, request, false);
}

::grpc::ClientAsyncResponseReader< ::MADS::GetTagSetResponse>* MADS_Service::Stub::AsyncgetTagSetRaw(::grpc::ClientContext* context, const ::MADS::GetTagSetRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncgetTagSetRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status MADS_Service::Stub::createTagSet(::grpc::ClientContext* context, const ::MADS::CreateTagSetRequest& request, ::MADS::CreateTagSetResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_createTagSet_, context, request, response);
}

void MADS_Service::Stub::experimental_async::createTagSet(::grpc::ClientContext* context, const ::MADS::CreateTagSetRequest* request, ::MADS::CreateTagSetResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_createTagSet_, context, request, response, std::move(f));
}

void MADS_Service::Stub::experimental_async::createTagSet(::grpc::ClientContext* context, const ::MADS::CreateTagSetRequest* request, ::MADS::CreateTagSetResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_createTagSet_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::MADS::CreateTagSetResponse>* MADS_Service::Stub::PrepareAsynccreateTagSetRaw(::grpc::ClientContext* context, const ::MADS::CreateTagSetRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::MADS::CreateTagSetResponse>::Create(channel_.get(), cq, rpcmethod_createTagSet_, context, request, false);
}

::grpc::ClientAsyncResponseReader< ::MADS::CreateTagSetResponse>* MADS_Service::Stub::AsynccreateTagSetRaw(::grpc::ClientContext* context, const ::MADS::CreateTagSetRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsynccreateTagSetRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status MADS_Service::Stub::getTags(::grpc::ClientContext* context, const ::MADS::GetTagsRequest& request, ::MADS::GetTagsResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_getTags_, context, request, response);
}

void MADS_Service::Stub::experimental_async::getTags(::grpc::ClientContext* context, const ::MADS::GetTagsRequest* request, ::MADS::GetTagsResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_getTags_, context, request, response, std::move(f));
}

void MADS_Service::Stub::experimental_async::getTags(::grpc::ClientContext* context, const ::MADS::GetTagsRequest* request, ::MADS::GetTagsResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_getTags_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::MADS::GetTagsResponse>* MADS_Service::Stub::PrepareAsyncgetTagsRaw(::grpc::ClientContext* context, const ::MADS::GetTagsRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::MADS::GetTagsResponse>::Create(channel_.get(), cq, rpcmethod_getTags_, context, request, false);
}

::grpc::ClientAsyncResponseReader< ::MADS::GetTagsResponse>* MADS_Service::Stub::AsyncgetTagsRaw(::grpc::ClientContext* context, const ::MADS::GetTagsRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncgetTagsRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status MADS_Service::Stub::getTag(::grpc::ClientContext* context, const ::MADS::GetTagRequest& request, ::MADS::GetTagResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_getTag_, context, request, response);
}

void MADS_Service::Stub::experimental_async::getTag(::grpc::ClientContext* context, const ::MADS::GetTagRequest* request, ::MADS::GetTagResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_getTag_, context, request, response, std::move(f));
}

void MADS_Service::Stub::experimental_async::getTag(::grpc::ClientContext* context, const ::MADS::GetTagRequest* request, ::MADS::GetTagResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_getTag_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::MADS::GetTagResponse>* MADS_Service::Stub::PrepareAsyncgetTagRaw(::grpc::ClientContext* context, const ::MADS::GetTagRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::MADS::GetTagResponse>::Create(channel_.get(), cq, rpcmethod_getTag_, context, request, false);
}

::grpc::ClientAsyncResponseReader< ::MADS::GetTagResponse>* MADS_Service::Stub::AsyncgetTagRaw(::grpc::ClientContext* context, const ::MADS::GetTagRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncgetTagRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status MADS_Service::Stub::createOrGetTag(::grpc::ClientContext* context, const ::MADS::CreateTagRequest& request, ::MADS::CreateTagResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_createOrGetTag_, context, request, response);
}

void MADS_Service::Stub::experimental_async::createOrGetTag(::grpc::ClientContext* context, const ::MADS::CreateTagRequest* request, ::MADS::CreateTagResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_createOrGetTag_, context, request, response, std::move(f));
}

void MADS_Service::Stub::experimental_async::createOrGetTag(::grpc::ClientContext* context, const ::MADS::CreateTagRequest* request, ::MADS::CreateTagResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_createOrGetTag_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::MADS::CreateTagResponse>* MADS_Service::Stub::PrepareAsynccreateOrGetTagRaw(::grpc::ClientContext* context, const ::MADS::CreateTagRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::MADS::CreateTagResponse>::Create(channel_.get(), cq, rpcmethod_createOrGetTag_, context, request, false);
}

::grpc::ClientAsyncResponseReader< ::MADS::CreateTagResponse>* MADS_Service::Stub::AsynccreateOrGetTagRaw(::grpc::ClientContext* context, const ::MADS::CreateTagRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsynccreateOrGetTagRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status MADS_Service::Stub::getTaggings(::grpc::ClientContext* context, const ::MADS::GetTaggingsRequest& request, ::MADS::GetTaggingsResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_getTaggings_, context, request, response);
}

void MADS_Service::Stub::experimental_async::getTaggings(::grpc::ClientContext* context, const ::MADS::GetTaggingsRequest* request, ::MADS::GetTaggingsResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_getTaggings_, context, request, response, std::move(f));
}

void MADS_Service::Stub::experimental_async::getTaggings(::grpc::ClientContext* context, const ::MADS::GetTaggingsRequest* request, ::MADS::GetTaggingsResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_getTaggings_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::MADS::GetTaggingsResponse>* MADS_Service::Stub::PrepareAsyncgetTaggingsRaw(::grpc::ClientContext* context, const ::MADS::GetTaggingsRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::MADS::GetTaggingsResponse>::Create(channel_.get(), cq, rpcmethod_getTaggings_, context, request, false);
}

::grpc::ClientAsyncResponseReader< ::MADS::GetTaggingsResponse>* MADS_Service::Stub::AsyncgetTaggingsRaw(::grpc::ClientContext* context, const ::MADS::GetTaggingsRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncgetTaggingsRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status MADS_Service::Stub::getTagging(::grpc::ClientContext* context, const ::MADS::GetTaggingRequest& request, ::MADS::GetTaggingResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_getTagging_, context, request, response);
}

void MADS_Service::Stub::experimental_async::getTagging(::grpc::ClientContext* context, const ::MADS::GetTaggingRequest* request, ::MADS::GetTaggingResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_getTagging_, context, request, response, std::move(f));
}

void MADS_Service::Stub::experimental_async::getTagging(::grpc::ClientContext* context, const ::MADS::GetTaggingRequest* request, ::MADS::GetTaggingResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_getTagging_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::MADS::GetTaggingResponse>* MADS_Service::Stub::PrepareAsyncgetTaggingRaw(::grpc::ClientContext* context, const ::MADS::GetTaggingRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::MADS::GetTaggingResponse>::Create(channel_.get(), cq, rpcmethod_getTagging_, context, request, false);
}

::grpc::ClientAsyncResponseReader< ::MADS::GetTaggingResponse>* MADS_Service::Stub::AsyncgetTaggingRaw(::grpc::ClientContext* context, const ::MADS::GetTaggingRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncgetTaggingRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status MADS_Service::Stub::createTagging(::grpc::ClientContext* context, const ::MADS::CreateTaggingRequest& request, ::MADS::CreateTaggingResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_createTagging_, context, request, response);
}

void MADS_Service::Stub::experimental_async::createTagging(::grpc::ClientContext* context, const ::MADS::CreateTaggingRequest* request, ::MADS::CreateTaggingResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_createTagging_, context, request, response, std::move(f));
}

void MADS_Service::Stub::experimental_async::createTagging(::grpc::ClientContext* context, const ::MADS::CreateTaggingRequest* request, ::MADS::CreateTaggingResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_createTagging_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::MADS::CreateTaggingResponse>* MADS_Service::Stub::PrepareAsynccreateTaggingRaw(::grpc::ClientContext* context, const ::MADS::CreateTaggingRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::MADS::CreateTaggingResponse>::Create(channel_.get(), cq, rpcmethod_createTagging_, context, request, false);
}

::grpc::ClientAsyncResponseReader< ::MADS::CreateTaggingResponse>* MADS_Service::Stub::AsynccreateTaggingRaw(::grpc::ClientContext* context, const ::MADS::CreateTaggingRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsynccreateTaggingRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status MADS_Service::Stub::reConnectDB(::grpc::ClientContext* context, const ::MADS::Empty& request, ::MADS::Empty* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_reConnectDB_, context, request, response);
}

void MADS_Service::Stub::experimental_async::reConnectDB(::grpc::ClientContext* context, const ::MADS::Empty* request, ::MADS::Empty* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_reConnectDB_, context, request, response, std::move(f));
}

void MADS_Service::Stub::experimental_async::reConnectDB(::grpc::ClientContext* context, const ::MADS::Empty* request, ::MADS::Empty* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_reConnectDB_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::MADS::Empty>* MADS_Service::Stub::PrepareAsyncreConnectDBRaw(::grpc::ClientContext* context, const ::MADS::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::MADS::Empty>::Create(channel_.get(), cq, rpcmethod_reConnectDB_, context, request, false);
}

::grpc::ClientAsyncResponseReader< ::MADS::Empty>* MADS_Service::Stub::AsyncreConnectDBRaw(::grpc::ClientContext* context, const ::MADS::Empty& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncreConnectDBRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status MADS_Service::Stub::stopService(::grpc::ClientContext* context, const ::MADS::Empty& request, ::MADS::Empty* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_stopService_, context, request, response);
}

void MADS_Service::Stub::experimental_async::stopService(::grpc::ClientContext* context, const ::MADS::Empty* request, ::MADS::Empty* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_stopService_, context, request, response, std::move(f));
}

void MADS_Service::Stub::experimental_async::stopService(::grpc::ClientContext* context, const ::MADS::Empty* request, ::MADS::Empty* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_stopService_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::MADS::Empty>* MADS_Service::Stub::PrepareAsyncstopServiceRaw(::grpc::ClientContext* context, const ::MADS::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::MADS::Empty>::Create(channel_.get(), cq, rpcmethod_stopService_, context, request, false);
}

::grpc::ClientAsyncResponseReader< ::MADS::Empty>* MADS_Service::Stub::AsyncstopServiceRaw(::grpc::ClientContext* context, const ::MADS::Empty& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncstopServiceRaw(context, request, cq);
  result->StartCall();
  return result;
}

MADS_Service::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      MADS_Service_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< MADS_Service::Service, ::MADS::GetObjectRequest, ::MADS::GetObjectResponse>(
          [](MADS_Service::Service* service,
             ::grpc::ServerContext* ctx,
             const ::MADS::GetObjectRequest* req,
             ::MADS::GetObjectResponse* resp) {
               return service->getObject(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      MADS_Service_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< MADS_Service::Service, ::MADS::CreateObjectRequest, ::MADS::CreateObjectResponse>(
          [](MADS_Service::Service* service,
             ::grpc::ServerContext* ctx,
             const ::MADS::CreateObjectRequest* req,
             ::MADS::CreateObjectResponse* resp) {
               return service->createObject(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      MADS_Service_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< MADS_Service::Service, ::MADS::GetTagSetsRequest, ::MADS::GetTagSetsResponse>(
          [](MADS_Service::Service* service,
             ::grpc::ServerContext* ctx,
             const ::MADS::GetTagSetsRequest* req,
             ::MADS::GetTagSetsResponse* resp) {
               return service->getTagSets(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      MADS_Service_method_names[3],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< MADS_Service::Service, ::MADS::GetTagSetRequest, ::MADS::GetTagSetResponse>(
          [](MADS_Service::Service* service,
             ::grpc::ServerContext* ctx,
             const ::MADS::GetTagSetRequest* req,
             ::MADS::GetTagSetResponse* resp) {
               return service->getTagSet(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      MADS_Service_method_names[4],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< MADS_Service::Service, ::MADS::CreateTagSetRequest, ::MADS::CreateTagSetResponse>(
          [](MADS_Service::Service* service,
             ::grpc::ServerContext* ctx,
             const ::MADS::CreateTagSetRequest* req,
             ::MADS::CreateTagSetResponse* resp) {
               return service->createTagSet(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      MADS_Service_method_names[5],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< MADS_Service::Service, ::MADS::GetTagsRequest, ::MADS::GetTagsResponse>(
          [](MADS_Service::Service* service,
             ::grpc::ServerContext* ctx,
             const ::MADS::GetTagsRequest* req,
             ::MADS::GetTagsResponse* resp) {
               return service->getTags(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      MADS_Service_method_names[6],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< MADS_Service::Service, ::MADS::GetTagRequest, ::MADS::GetTagResponse>(
          [](MADS_Service::Service* service,
             ::grpc::ServerContext* ctx,
             const ::MADS::GetTagRequest* req,
             ::MADS::GetTagResponse* resp) {
               return service->getTag(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      MADS_Service_method_names[7],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< MADS_Service::Service, ::MADS::CreateTagRequest, ::MADS::CreateTagResponse>(
          [](MADS_Service::Service* service,
             ::grpc::ServerContext* ctx,
             const ::MADS::CreateTagRequest* req,
             ::MADS::CreateTagResponse* resp) {
               return service->createOrGetTag(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      MADS_Service_method_names[8],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< MADS_Service::Service, ::MADS::GetTaggingsRequest, ::MADS::GetTaggingsResponse>(
          [](MADS_Service::Service* service,
             ::grpc::ServerContext* ctx,
             const ::MADS::GetTaggingsRequest* req,
             ::MADS::GetTaggingsResponse* resp) {
               return service->getTaggings(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      MADS_Service_method_names[9],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< MADS_Service::Service, ::MADS::GetTaggingRequest, ::MADS::GetTaggingResponse>(
          [](MADS_Service::Service* service,
             ::grpc::ServerContext* ctx,
             const ::MADS::GetTaggingRequest* req,
             ::MADS::GetTaggingResponse* resp) {
               return service->getTagging(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      MADS_Service_method_names[10],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< MADS_Service::Service, ::MADS::CreateTaggingRequest, ::MADS::CreateTaggingResponse>(
          [](MADS_Service::Service* service,
             ::grpc::ServerContext* ctx,
             const ::MADS::CreateTaggingRequest* req,
             ::MADS::CreateTaggingResponse* resp) {
               return service->createTagging(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      MADS_Service_method_names[11],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< MADS_Service::Service, ::MADS::Empty, ::MADS::Empty>(
          [](MADS_Service::Service* service,
             ::grpc::ServerContext* ctx,
             const ::MADS::Empty* req,
             ::MADS::Empty* resp) {
               return service->reConnectDB(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      MADS_Service_method_names[12],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< MADS_Service::Service, ::MADS::Empty, ::MADS::Empty>(
          [](MADS_Service::Service* service,
             ::grpc::ServerContext* ctx,
             const ::MADS::Empty* req,
             ::MADS::Empty* resp) {
               return service->stopService(ctx, req, resp);
             }, this)));
}

MADS_Service::Service::~Service() {
}

::grpc::Status MADS_Service::Service::getObject(::grpc::ServerContext* context, const ::MADS::GetObjectRequest* request, ::MADS::GetObjectResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status MADS_Service::Service::createObject(::grpc::ServerContext* context, const ::MADS::CreateObjectRequest* request, ::MADS::CreateObjectResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status MADS_Service::Service::getTagSets(::grpc::ServerContext* context, const ::MADS::GetTagSetsRequest* request, ::MADS::GetTagSetsResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status MADS_Service::Service::getTagSet(::grpc::ServerContext* context, const ::MADS::GetTagSetRequest* request, ::MADS::GetTagSetResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status MADS_Service::Service::createTagSet(::grpc::ServerContext* context, const ::MADS::CreateTagSetRequest* request, ::MADS::CreateTagSetResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status MADS_Service::Service::getTags(::grpc::ServerContext* context, const ::MADS::GetTagsRequest* request, ::MADS::GetTagsResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status MADS_Service::Service::getTag(::grpc::ServerContext* context, const ::MADS::GetTagRequest* request, ::MADS::GetTagResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status MADS_Service::Service::createOrGetTag(::grpc::ServerContext* context, const ::MADS::CreateTagRequest* request, ::MADS::CreateTagResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status MADS_Service::Service::getTaggings(::grpc::ServerContext* context, const ::MADS::GetTaggingsRequest* request, ::MADS::GetTaggingsResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status MADS_Service::Service::getTagging(::grpc::ServerContext* context, const ::MADS::GetTaggingRequest* request, ::MADS::GetTaggingResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status MADS_Service::Service::createTagging(::grpc::ServerContext* context, const ::MADS::CreateTaggingRequest* request, ::MADS::CreateTaggingResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status MADS_Service::Service::reConnectDB(::grpc::ServerContext* context, const ::MADS::Empty* request, ::MADS::Empty* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status MADS_Service::Service::stopService(::grpc::ServerContext* context, const ::MADS::Empty* request, ::MADS::Empty* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace MADS

