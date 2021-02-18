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

    def get_tagset_by_id(self, tagset_id):
        try:
            get_tagset_request = MADS_pb2.GetTagSetRequestById(id=tagset_id)
            response = self.grpc_stub.getTagSetById(get_tagset_request)
            return json.loads(MessageToJson(response.tagset))
        except:
            return json.loads('{"Error": "Error loading tagset"}')

    def get_tagset_by_name(self, tagset_name):
        try:
            get_tagset_request = MADS_pb2.GetTagSetRequestByName(name=tagset_name)
            response = self.grpc_stub.getTagSetByName(get_tagset_request)
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

    def create_alphanumerical_tag(self, tag_name, tagset_id):
        try:
            alphanumerical_value = MADS_pb2.AlphanumericalValue(value=tag_name)
            create_tag_request = MADS_pb2.CreateTagRequest(tagSetId=tagset_id, alphanumerical=alphanumerical_value)
            response = self.grpc_stub.createOrGetTag(create_tag_request)
            return json.loads(MessageToJson(response.tag))
        except:
            return json.loads('{"Error": "Error creating alphanumerical tag"}')

    def create_numerical_tag(self, tag_value, tagset_id):
        try:
            numerical_value = MADS_pb2.NumericalValue(value=str(tag_value))
            create_tag_request = MADS_pb2.CreateTagRequest(tagSetId=tagset_id, numerical=numerical_value)
            response = self.grpc_stub.createOrGetTag(create_tag_request)
            return json.loads(MessageToJson(response.tag))
        except:
            return json.loads('{"Error": "Error creating numerical tag"}')

    def create_date_tag(self, year, month, day, tagset_id):
        try:
            date_value = MADS_pb2.DateValue(value=str(year)+'-'+str(month)+'-'+str(day))
            create_tag_request = MADS_pb2.CreateTagRequest(tagSetId=tagset_id, date=date_value)
            response = self.grpc_stub.createOrGetTag(create_tag_request)
            return json.loads(MessageToJson(response.tag))
        except:
            return json.loads('{"Error": "Error creating date tag"}')

    def create_tagging(self, tag_id, object_id):
        try:
            import pdb; pdb.set_trace()
            create_tagging_request = MADS_pb2.CreateTaggingRequest(tagId=tag_id, objectId=object_id)
            response = self.grpc_stub.createTagging(create_tagging_request)
            return json.loads(MessageToJson(response.tagging))
        except:
            return json.loads('{"Error": "Error creating tagging"}')

