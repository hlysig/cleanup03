import grpc

import OC_pb2
import OC_pb2_grpc
import json
from google.protobuf.json_format import MessageToJson


class MADSClient:
    def __init__(self, grpc_host='core', grpc_port=26026):
        self.grpc_channel = grpc.insecure_channel('127.0.0.1:26026')
        self.grpc_stub = OC_pb2_grpc.OCServiceStub(self.grpc_channel)

    def get_tag(self, tag_id):
        get_tag_request = OC_pb2.GetTagRequest(id=1)
        response = self.grpc_stub.getTag(get_tag_request)
        return json.loads(MessageToJson(response.tag))
