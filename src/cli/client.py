import grpc
import sys

import MADS_pb2
import MADS_pb2_grpc
import json
from google.protobuf.json_format import MessageToJson


class MADSClient:
    def __init__(self, grpc_host='core', grpc_port=26026):
        self.grpc_channel = grpc.insecure_channel('127.0.0.1:26026')
        self.grpc_stub = MADS_pb2_grpc.MADS_ServiceStub(self.grpc_channel)

    def get_object(self, object_id):
        try:
            get_object_request = MADS_pb2.GetObjectRequest(id=object_id)
            response = self.grpc_stub.getObject(get_object_request)
            return json.loads(MessageToJson(response.object))
        except:
            return json.loads('{"Error": "Error loading object"}')

    def get_tagsets(self):
        try:
            get_tagsets_request = MADS_pb2.Empty()
            response = self.grpc_stub.getTagSets(get_tagsets_request)
            return [json.loads(MessageToJson(x)) for x in response.tagsets]
        except:
            return json.loads('{"Error": "Error loading all tagsets"}')

    def get_tagset(self, tagset_id):
        try:
            get_tagset_request = MADS_pb2.GetTagSetRequest(id=tagset_id)
            response = self.grpc_stub.getTagSet(get_tagset_request)
            return json.loads(MessageToJson(response.tagset))
        except:
            return json.loads('{"Error": "Error loading tagset"}')

    def get_tags(self):
        try:
            get_tags_request = MADS_pb2.Empty()
            response = self.grpc_stub.getTags(get_tags_request)
            return [json.loads(MessageToJson(x)) for x in response.tags]
        except:
            return json.loads('{"Error": "Error loading all tags"}')

    def get_tag(self, tag_id):
        try:
            get_tag_request = MADS_pb2.GetTagRequest(id=tag_id)
            response = self.grpc_stub.getTag(get_tag_request)
            return json.loads(MessageToJson(response.tag))
        except:
            return json.loads('{"Error": "Error loading tag"}')

    def create_object(self, object_uri, object_filetype):
        try:
            create_object_request = MADS_pb2.CreateObjectRequest(URI=object_uri, fileType=object_filetype)
            response = self.grpc_stub.createObject(create_object_request)
            return json.loads(MessageToJson(response.object))
        except:
            return json.loads('{"Error": "Error creating object"}')

    def create_tagset(self, tagset_name, tagset_description, tagset_type):
        try:
            create_tagset_request = MADS_pb2.CreateTagSetRequest(name=tagset_name, description=tagset_description, type=tagset_type)
            response = self.grpc_stub.createTagSet(create_tagset_request)
            return json.loads(MessageToJson(response.tagset))
        except:
            return json.loads('{"Error": "Error creating tagset"}')

