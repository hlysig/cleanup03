import grpc
import sys

import OC_pb2
import OC_pb2_grpc
import json
from google.protobuf.json_format import MessageToJson


class MADSClient:
    def __init__(self, grpc_host='core', grpc_port=26026):
        self.grpc_channel = grpc.insecure_channel('127.0.0.1:26026')
        self.grpc_stub = OC_pb2_grpc.OCServiceStub(self.grpc_channel)

    def get_tagsets(self):
        try:
            get_tagsets_request = OC_pb2.GetTagSetsRequest()
            response = self.grpc_stub.getTagSets(get_tagsets_request)
            return [json.loads(MessageToJson(x)) for x in response.tagsets]
        except:
            return json.loads('{"Error": "Error loading all tagsets"}')

    def get_tagset(self, tagset_id):
        try:
            get_tagset_request = OC_pb2.GetTagSetRequest(id=tagset_id)
            response = self.grpc_stub.getTagSet(get_tagset_request)
            return json.loads(MessageToJson(response.tagset))
        except:
            return json.loads('{"Error": "Error loading tagset"}')

    def get_tags(self):
        try:
            get_tags_request = OC_pb2.GetTagsRequest()
            response = self.grpc_stub.getTags(get_tags_request)
            return [json.loads(MessageToJson(x)) for x in response.tags]
        except:
            return json.loads('{"Error": "Error loading all tags"}')

    def get_tag(self, tag_id):
        try:
            get_tag_request = OC_pb2.GetTagRequest(id=tag_id)
            response = self.grpc_stub.getTag(get_tag_request)
            return json.loads(MessageToJson(response.tag))
        except:
            return json.loads('{"Error": "Error loading tag"}')
