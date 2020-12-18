# Generated by the gRPC Python protocol compiler plugin. DO NOT EDIT!
"""Client and server classes corresponding to protobuf-defined services."""
import grpc

import OC_pb2 as OC__pb2


class OCServiceStub(object):
    """Missing associated documentation comment in .proto file."""

    def __init__(self, channel):
        """Constructor.

        Args:
            channel: A grpc.Channel.
        """
        self.getTagSets = channel.unary_unary(
                '/OC.OCService/getTagSets',
                request_serializer=OC__pb2.GetTagSetsRequest.SerializeToString,
                response_deserializer=OC__pb2.GetTagSetsResponse.FromString,
                )
        self.getTagSet = channel.unary_unary(
                '/OC.OCService/getTagSet',
                request_serializer=OC__pb2.GetTagSetRequest.SerializeToString,
                response_deserializer=OC__pb2.GetTagSetResponse.FromString,
                )
        self.getTags = channel.unary_unary(
                '/OC.OCService/getTags',
                request_serializer=OC__pb2.GetTagsRequest.SerializeToString,
                response_deserializer=OC__pb2.GetTagsResponse.FromString,
                )
        self.getTag = channel.unary_unary(
                '/OC.OCService/getTag',
                request_serializer=OC__pb2.GetTagRequest.SerializeToString,
                response_deserializer=OC__pb2.GetTagResponse.FromString,
                )
        self.putTag = channel.unary_unary(
                '/OC.OCService/putTag',
                request_serializer=OC__pb2.PutTagRequest.SerializeToString,
                response_deserializer=OC__pb2.PutTagResponse.FromString,
                )
        self.reConnectDB = channel.unary_unary(
                '/OC.OCService/reConnectDB',
                request_serializer=OC__pb2.Empty.SerializeToString,
                response_deserializer=OC__pb2.Empty.FromString,
                )
        self.stopService = channel.unary_unary(
                '/OC.OCService/stopService',
                request_serializer=OC__pb2.Empty.SerializeToString,
                response_deserializer=OC__pb2.Empty.FromString,
                )


class OCServiceServicer(object):
    """Missing associated documentation comment in .proto file."""

    def getTagSets(self, request, context):
        """Missing associated documentation comment in .proto file."""
        context.set_code(grpc.StatusCode.UNIMPLEMENTED)
        context.set_details('Method not implemented!')
        raise NotImplementedError('Method not implemented!')

    def getTagSet(self, request, context):
        """Missing associated documentation comment in .proto file."""
        context.set_code(grpc.StatusCode.UNIMPLEMENTED)
        context.set_details('Method not implemented!')
        raise NotImplementedError('Method not implemented!')

    def getTags(self, request, context):
        """Missing associated documentation comment in .proto file."""
        context.set_code(grpc.StatusCode.UNIMPLEMENTED)
        context.set_details('Method not implemented!')
        raise NotImplementedError('Method not implemented!')

    def getTag(self, request, context):
        """Missing associated documentation comment in .proto file."""
        context.set_code(grpc.StatusCode.UNIMPLEMENTED)
        context.set_details('Method not implemented!')
        raise NotImplementedError('Method not implemented!')

    def putTag(self, request, context):
        """Missing associated documentation comment in .proto file."""
        context.set_code(grpc.StatusCode.UNIMPLEMENTED)
        context.set_details('Method not implemented!')
        raise NotImplementedError('Method not implemented!')

    def reConnectDB(self, request, context):
        """Future functionality
        """
        context.set_code(grpc.StatusCode.UNIMPLEMENTED)
        context.set_details('Method not implemented!')
        raise NotImplementedError('Method not implemented!')

    def stopService(self, request, context):
        """Missing associated documentation comment in .proto file."""
        context.set_code(grpc.StatusCode.UNIMPLEMENTED)
        context.set_details('Method not implemented!')
        raise NotImplementedError('Method not implemented!')


def add_OCServiceServicer_to_server(servicer, server):
    rpc_method_handlers = {
            'getTagSets': grpc.unary_unary_rpc_method_handler(
                    servicer.getTagSets,
                    request_deserializer=OC__pb2.GetTagSetsRequest.FromString,
                    response_serializer=OC__pb2.GetTagSetsResponse.SerializeToString,
            ),
            'getTagSet': grpc.unary_unary_rpc_method_handler(
                    servicer.getTagSet,
                    request_deserializer=OC__pb2.GetTagSetRequest.FromString,
                    response_serializer=OC__pb2.GetTagSetResponse.SerializeToString,
            ),
            'getTags': grpc.unary_unary_rpc_method_handler(
                    servicer.getTags,
                    request_deserializer=OC__pb2.GetTagsRequest.FromString,
                    response_serializer=OC__pb2.GetTagsResponse.SerializeToString,
            ),
            'getTag': grpc.unary_unary_rpc_method_handler(
                    servicer.getTag,
                    request_deserializer=OC__pb2.GetTagRequest.FromString,
                    response_serializer=OC__pb2.GetTagResponse.SerializeToString,
            ),
            'putTag': grpc.unary_unary_rpc_method_handler(
                    servicer.putTag,
                    request_deserializer=OC__pb2.PutTagRequest.FromString,
                    response_serializer=OC__pb2.PutTagResponse.SerializeToString,
            ),
            'reConnectDB': grpc.unary_unary_rpc_method_handler(
                    servicer.reConnectDB,
                    request_deserializer=OC__pb2.Empty.FromString,
                    response_serializer=OC__pb2.Empty.SerializeToString,
            ),
            'stopService': grpc.unary_unary_rpc_method_handler(
                    servicer.stopService,
                    request_deserializer=OC__pb2.Empty.FromString,
                    response_serializer=OC__pb2.Empty.SerializeToString,
            ),
    }
    generic_handler = grpc.method_handlers_generic_handler(
            'OC.OCService', rpc_method_handlers)
    server.add_generic_rpc_handlers((generic_handler,))


 # This class is part of an EXPERIMENTAL API.
class OCService(object):
    """Missing associated documentation comment in .proto file."""

    @staticmethod
    def getTagSets(request,
            target,
            options=(),
            channel_credentials=None,
            call_credentials=None,
            insecure=False,
            compression=None,
            wait_for_ready=None,
            timeout=None,
            metadata=None):
        return grpc.experimental.unary_unary(request, target, '/OC.OCService/getTagSets',
            OC__pb2.GetTagSetsRequest.SerializeToString,
            OC__pb2.GetTagSetsResponse.FromString,
            options, channel_credentials,
            insecure, call_credentials, compression, wait_for_ready, timeout, metadata)

    @staticmethod
    def getTagSet(request,
            target,
            options=(),
            channel_credentials=None,
            call_credentials=None,
            insecure=False,
            compression=None,
            wait_for_ready=None,
            timeout=None,
            metadata=None):
        return grpc.experimental.unary_unary(request, target, '/OC.OCService/getTagSet',
            OC__pb2.GetTagSetRequest.SerializeToString,
            OC__pb2.GetTagSetResponse.FromString,
            options, channel_credentials,
            insecure, call_credentials, compression, wait_for_ready, timeout, metadata)

    @staticmethod
    def getTags(request,
            target,
            options=(),
            channel_credentials=None,
            call_credentials=None,
            insecure=False,
            compression=None,
            wait_for_ready=None,
            timeout=None,
            metadata=None):
        return grpc.experimental.unary_unary(request, target, '/OC.OCService/getTags',
            OC__pb2.GetTagsRequest.SerializeToString,
            OC__pb2.GetTagsResponse.FromString,
            options, channel_credentials,
            insecure, call_credentials, compression, wait_for_ready, timeout, metadata)

    @staticmethod
    def getTag(request,
            target,
            options=(),
            channel_credentials=None,
            call_credentials=None,
            insecure=False,
            compression=None,
            wait_for_ready=None,
            timeout=None,
            metadata=None):
        return grpc.experimental.unary_unary(request, target, '/OC.OCService/getTag',
            OC__pb2.GetTagRequest.SerializeToString,
            OC__pb2.GetTagResponse.FromString,
            options, channel_credentials,
            insecure, call_credentials, compression, wait_for_ready, timeout, metadata)

    @staticmethod
    def putTag(request,
            target,
            options=(),
            channel_credentials=None,
            call_credentials=None,
            insecure=False,
            compression=None,
            wait_for_ready=None,
            timeout=None,
            metadata=None):
        return grpc.experimental.unary_unary(request, target, '/OC.OCService/putTag',
            OC__pb2.PutTagRequest.SerializeToString,
            OC__pb2.PutTagResponse.FromString,
            options, channel_credentials,
            insecure, call_credentials, compression, wait_for_ready, timeout, metadata)

    @staticmethod
    def reConnectDB(request,
            target,
            options=(),
            channel_credentials=None,
            call_credentials=None,
            insecure=False,
            compression=None,
            wait_for_ready=None,
            timeout=None,
            metadata=None):
        return grpc.experimental.unary_unary(request, target, '/OC.OCService/reConnectDB',
            OC__pb2.Empty.SerializeToString,
            OC__pb2.Empty.FromString,
            options, channel_credentials,
            insecure, call_credentials, compression, wait_for_ready, timeout, metadata)

    @staticmethod
    def stopService(request,
            target,
            options=(),
            channel_credentials=None,
            call_credentials=None,
            insecure=False,
            compression=None,
            wait_for_ready=None,
            timeout=None,
            metadata=None):
        return grpc.experimental.unary_unary(request, target, '/OC.OCService/stopService',
            OC__pb2.Empty.SerializeToString,
            OC__pb2.Empty.FromString,
            options, channel_credentials,
            insecure, call_credentials, compression, wait_for_ready, timeout, metadata)
