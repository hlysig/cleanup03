# Generated by the gRPC Python protocol compiler plugin. DO NOT EDIT!
"""Client and server classes corresponding to protobuf-defined services."""
import grpc

import MADS_pb2 as MADS__pb2


class MADS_ServiceStub(object):
    """Service

    """

    def __init__(self, channel):
        """Constructor.

        Args:
            channel: A grpc.Channel.
        """
        self.getObject = channel.unary_unary(
                '/MADS.MADS_Service/getObject',
                request_serializer=MADS__pb2.GetObjectRequest.SerializeToString,
                response_deserializer=MADS__pb2.GetObjectResponse.FromString,
                )
        self.createObject = channel.unary_unary(
                '/MADS.MADS_Service/createObject',
                request_serializer=MADS__pb2.CreateObjectRequest.SerializeToString,
                response_deserializer=MADS__pb2.CreateObjectResponse.FromString,
                )
        self.getTagSets = channel.unary_unary(
                '/MADS.MADS_Service/getTagSets',
                request_serializer=MADS__pb2.GetTagSetsRequest.SerializeToString,
                response_deserializer=MADS__pb2.GetTagSetsResponse.FromString,
                )
        self.getTagSet = channel.unary_unary(
                '/MADS.MADS_Service/getTagSet',
                request_serializer=MADS__pb2.GetTagSetRequest.SerializeToString,
                response_deserializer=MADS__pb2.GetTagSetResponse.FromString,
                )
        self.createTagSet = channel.unary_unary(
                '/MADS.MADS_Service/createTagSet',
                request_serializer=MADS__pb2.CreateTagSetRequest.SerializeToString,
                response_deserializer=MADS__pb2.CreateTagSetResponse.FromString,
                )
        self.getTags = channel.unary_unary(
                '/MADS.MADS_Service/getTags',
                request_serializer=MADS__pb2.GetTagsRequest.SerializeToString,
                response_deserializer=MADS__pb2.GetTagsResponse.FromString,
                )
        self.getTag = channel.unary_unary(
                '/MADS.MADS_Service/getTag',
                request_serializer=MADS__pb2.GetTagRequest.SerializeToString,
                response_deserializer=MADS__pb2.GetTagResponse.FromString,
                )
        self.createOrGetTag = channel.unary_unary(
                '/MADS.MADS_Service/createOrGetTag',
                request_serializer=MADS__pb2.CreateTagRequest.SerializeToString,
                response_deserializer=MADS__pb2.CreateTagResponse.FromString,
                )
        self.getTaggings = channel.unary_unary(
                '/MADS.MADS_Service/getTaggings',
                request_serializer=MADS__pb2.GetTaggingsRequest.SerializeToString,
                response_deserializer=MADS__pb2.GetTaggingsResponse.FromString,
                )
        self.getTagging = channel.unary_unary(
                '/MADS.MADS_Service/getTagging',
                request_serializer=MADS__pb2.GetTaggingRequest.SerializeToString,
                response_deserializer=MADS__pb2.GetTaggingResponse.FromString,
                )
        self.createTagging = channel.unary_unary(
                '/MADS.MADS_Service/createTagging',
                request_serializer=MADS__pb2.CreateTaggingRequest.SerializeToString,
                response_deserializer=MADS__pb2.CreateTaggingResponse.FromString,
                )
        self.reConnectDB = channel.unary_unary(
                '/MADS.MADS_Service/reConnectDB',
                request_serializer=MADS__pb2.Empty.SerializeToString,
                response_deserializer=MADS__pb2.Empty.FromString,
                )
        self.stopService = channel.unary_unary(
                '/MADS.MADS_Service/stopService',
                request_serializer=MADS__pb2.Empty.SerializeToString,
                response_deserializer=MADS__pb2.Empty.FromString,
                )


class MADS_ServiceServicer(object):
    """Service

    """

    def getObject(self, request, context):
        """Object
        """
        context.set_code(grpc.StatusCode.UNIMPLEMENTED)
        context.set_details('Method not implemented!')
        raise NotImplementedError('Method not implemented!')

    def createObject(self, request, context):
        """Missing associated documentation comment in .proto file."""
        context.set_code(grpc.StatusCode.UNIMPLEMENTED)
        context.set_details('Method not implemented!')
        raise NotImplementedError('Method not implemented!')

    def getTagSets(self, request, context):
        """TagSet
        """
        context.set_code(grpc.StatusCode.UNIMPLEMENTED)
        context.set_details('Method not implemented!')
        raise NotImplementedError('Method not implemented!')

    def getTagSet(self, request, context):
        """Missing associated documentation comment in .proto file."""
        context.set_code(grpc.StatusCode.UNIMPLEMENTED)
        context.set_details('Method not implemented!')
        raise NotImplementedError('Method not implemented!')

    def createTagSet(self, request, context):
        """Missing associated documentation comment in .proto file."""
        context.set_code(grpc.StatusCode.UNIMPLEMENTED)
        context.set_details('Method not implemented!')
        raise NotImplementedError('Method not implemented!')

    def getTags(self, request, context):
        """Tag
        """
        context.set_code(grpc.StatusCode.UNIMPLEMENTED)
        context.set_details('Method not implemented!')
        raise NotImplementedError('Method not implemented!')

    def getTag(self, request, context):
        """Missing associated documentation comment in .proto file."""
        context.set_code(grpc.StatusCode.UNIMPLEMENTED)
        context.set_details('Method not implemented!')
        raise NotImplementedError('Method not implemented!')

    def createOrGetTag(self, request, context):
        """Missing associated documentation comment in .proto file."""
        context.set_code(grpc.StatusCode.UNIMPLEMENTED)
        context.set_details('Method not implemented!')
        raise NotImplementedError('Method not implemented!')

    def getTaggings(self, request, context):
        """Tagging
        """
        context.set_code(grpc.StatusCode.UNIMPLEMENTED)
        context.set_details('Method not implemented!')
        raise NotImplementedError('Method not implemented!')

    def getTagging(self, request, context):
        """Missing associated documentation comment in .proto file."""
        context.set_code(grpc.StatusCode.UNIMPLEMENTED)
        context.set_details('Method not implemented!')
        raise NotImplementedError('Method not implemented!')

    def createTagging(self, request, context):
        """Missing associated documentation comment in .proto file."""
        context.set_code(grpc.StatusCode.UNIMPLEMENTED)
        context.set_details('Method not implemented!')
        raise NotImplementedError('Method not implemented!')

    def reConnectDB(self, request, context):
        """Control RPC calls
        """
        context.set_code(grpc.StatusCode.UNIMPLEMENTED)
        context.set_details('Method not implemented!')
        raise NotImplementedError('Method not implemented!')

    def stopService(self, request, context):
        """Missing associated documentation comment in .proto file."""
        context.set_code(grpc.StatusCode.UNIMPLEMENTED)
        context.set_details('Method not implemented!')
        raise NotImplementedError('Method not implemented!')


def add_MADS_ServiceServicer_to_server(servicer, server):
    rpc_method_handlers = {
            'getObject': grpc.unary_unary_rpc_method_handler(
                    servicer.getObject,
                    request_deserializer=MADS__pb2.GetObjectRequest.FromString,
                    response_serializer=MADS__pb2.GetObjectResponse.SerializeToString,
            ),
            'createObject': grpc.unary_unary_rpc_method_handler(
                    servicer.createObject,
                    request_deserializer=MADS__pb2.CreateObjectRequest.FromString,
                    response_serializer=MADS__pb2.CreateObjectResponse.SerializeToString,
            ),
            'getTagSets': grpc.unary_unary_rpc_method_handler(
                    servicer.getTagSets,
                    request_deserializer=MADS__pb2.GetTagSetsRequest.FromString,
                    response_serializer=MADS__pb2.GetTagSetsResponse.SerializeToString,
            ),
            'getTagSet': grpc.unary_unary_rpc_method_handler(
                    servicer.getTagSet,
                    request_deserializer=MADS__pb2.GetTagSetRequest.FromString,
                    response_serializer=MADS__pb2.GetTagSetResponse.SerializeToString,
            ),
            'createTagSet': grpc.unary_unary_rpc_method_handler(
                    servicer.createTagSet,
                    request_deserializer=MADS__pb2.CreateTagSetRequest.FromString,
                    response_serializer=MADS__pb2.CreateTagSetResponse.SerializeToString,
            ),
            'getTags': grpc.unary_unary_rpc_method_handler(
                    servicer.getTags,
                    request_deserializer=MADS__pb2.GetTagsRequest.FromString,
                    response_serializer=MADS__pb2.GetTagsResponse.SerializeToString,
            ),
            'getTag': grpc.unary_unary_rpc_method_handler(
                    servicer.getTag,
                    request_deserializer=MADS__pb2.GetTagRequest.FromString,
                    response_serializer=MADS__pb2.GetTagResponse.SerializeToString,
            ),
            'createOrGetTag': grpc.unary_unary_rpc_method_handler(
                    servicer.createOrGetTag,
                    request_deserializer=MADS__pb2.CreateTagRequest.FromString,
                    response_serializer=MADS__pb2.CreateTagResponse.SerializeToString,
            ),
            'getTaggings': grpc.unary_unary_rpc_method_handler(
                    servicer.getTaggings,
                    request_deserializer=MADS__pb2.GetTaggingsRequest.FromString,
                    response_serializer=MADS__pb2.GetTaggingsResponse.SerializeToString,
            ),
            'getTagging': grpc.unary_unary_rpc_method_handler(
                    servicer.getTagging,
                    request_deserializer=MADS__pb2.GetTaggingRequest.FromString,
                    response_serializer=MADS__pb2.GetTaggingResponse.SerializeToString,
            ),
            'createTagging': grpc.unary_unary_rpc_method_handler(
                    servicer.createTagging,
                    request_deserializer=MADS__pb2.CreateTaggingRequest.FromString,
                    response_serializer=MADS__pb2.CreateTaggingResponse.SerializeToString,
            ),
            'reConnectDB': grpc.unary_unary_rpc_method_handler(
                    servicer.reConnectDB,
                    request_deserializer=MADS__pb2.Empty.FromString,
                    response_serializer=MADS__pb2.Empty.SerializeToString,
            ),
            'stopService': grpc.unary_unary_rpc_method_handler(
                    servicer.stopService,
                    request_deserializer=MADS__pb2.Empty.FromString,
                    response_serializer=MADS__pb2.Empty.SerializeToString,
            ),
    }
    generic_handler = grpc.method_handlers_generic_handler(
            'MADS.MADS_Service', rpc_method_handlers)
    server.add_generic_rpc_handlers((generic_handler,))


 # This class is part of an EXPERIMENTAL API.
class MADS_Service(object):
    """Service

    """

    @staticmethod
    def getObject(request,
            target,
            options=(),
            channel_credentials=None,
            call_credentials=None,
            insecure=False,
            compression=None,
            wait_for_ready=None,
            timeout=None,
            metadata=None):
        return grpc.experimental.unary_unary(request, target, '/MADS.MADS_Service/getObject',
            MADS__pb2.GetObjectRequest.SerializeToString,
            MADS__pb2.GetObjectResponse.FromString,
            options, channel_credentials,
            insecure, call_credentials, compression, wait_for_ready, timeout, metadata)

    @staticmethod
    def createObject(request,
            target,
            options=(),
            channel_credentials=None,
            call_credentials=None,
            insecure=False,
            compression=None,
            wait_for_ready=None,
            timeout=None,
            metadata=None):
        return grpc.experimental.unary_unary(request, target, '/MADS.MADS_Service/createObject',
            MADS__pb2.CreateObjectRequest.SerializeToString,
            MADS__pb2.CreateObjectResponse.FromString,
            options, channel_credentials,
            insecure, call_credentials, compression, wait_for_ready, timeout, metadata)

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
        return grpc.experimental.unary_unary(request, target, '/MADS.MADS_Service/getTagSets',
            MADS__pb2.GetTagSetsRequest.SerializeToString,
            MADS__pb2.GetTagSetsResponse.FromString,
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
        return grpc.experimental.unary_unary(request, target, '/MADS.MADS_Service/getTagSet',
            MADS__pb2.GetTagSetRequest.SerializeToString,
            MADS__pb2.GetTagSetResponse.FromString,
            options, channel_credentials,
            insecure, call_credentials, compression, wait_for_ready, timeout, metadata)

    @staticmethod
    def createTagSet(request,
            target,
            options=(),
            channel_credentials=None,
            call_credentials=None,
            insecure=False,
            compression=None,
            wait_for_ready=None,
            timeout=None,
            metadata=None):
        return grpc.experimental.unary_unary(request, target, '/MADS.MADS_Service/createTagSet',
            MADS__pb2.CreateTagSetRequest.SerializeToString,
            MADS__pb2.CreateTagSetResponse.FromString,
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
        return grpc.experimental.unary_unary(request, target, '/MADS.MADS_Service/getTags',
            MADS__pb2.GetTagsRequest.SerializeToString,
            MADS__pb2.GetTagsResponse.FromString,
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
        return grpc.experimental.unary_unary(request, target, '/MADS.MADS_Service/getTag',
            MADS__pb2.GetTagRequest.SerializeToString,
            MADS__pb2.GetTagResponse.FromString,
            options, channel_credentials,
            insecure, call_credentials, compression, wait_for_ready, timeout, metadata)

    @staticmethod
    def createOrGetTag(request,
            target,
            options=(),
            channel_credentials=None,
            call_credentials=None,
            insecure=False,
            compression=None,
            wait_for_ready=None,
            timeout=None,
            metadata=None):
        return grpc.experimental.unary_unary(request, target, '/MADS.MADS_Service/createOrGetTag',
            MADS__pb2.CreateTagRequest.SerializeToString,
            MADS__pb2.CreateTagResponse.FromString,
            options, channel_credentials,
            insecure, call_credentials, compression, wait_for_ready, timeout, metadata)

    @staticmethod
    def getTaggings(request,
            target,
            options=(),
            channel_credentials=None,
            call_credentials=None,
            insecure=False,
            compression=None,
            wait_for_ready=None,
            timeout=None,
            metadata=None):
        return grpc.experimental.unary_unary(request, target, '/MADS.MADS_Service/getTaggings',
            MADS__pb2.GetTaggingsRequest.SerializeToString,
            MADS__pb2.GetTaggingsResponse.FromString,
            options, channel_credentials,
            insecure, call_credentials, compression, wait_for_ready, timeout, metadata)

    @staticmethod
    def getTagging(request,
            target,
            options=(),
            channel_credentials=None,
            call_credentials=None,
            insecure=False,
            compression=None,
            wait_for_ready=None,
            timeout=None,
            metadata=None):
        return grpc.experimental.unary_unary(request, target, '/MADS.MADS_Service/getTagging',
            MADS__pb2.GetTaggingRequest.SerializeToString,
            MADS__pb2.GetTaggingResponse.FromString,
            options, channel_credentials,
            insecure, call_credentials, compression, wait_for_ready, timeout, metadata)

    @staticmethod
    def createTagging(request,
            target,
            options=(),
            channel_credentials=None,
            call_credentials=None,
            insecure=False,
            compression=None,
            wait_for_ready=None,
            timeout=None,
            metadata=None):
        return grpc.experimental.unary_unary(request, target, '/MADS.MADS_Service/createTagging',
            MADS__pb2.CreateTaggingRequest.SerializeToString,
            MADS__pb2.CreateTaggingResponse.FromString,
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
        return grpc.experimental.unary_unary(request, target, '/MADS.MADS_Service/reConnectDB',
            MADS__pb2.Empty.SerializeToString,
            MADS__pb2.Empty.FromString,
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
        return grpc.experimental.unary_unary(request, target, '/MADS.MADS_Service/stopService',
            MADS__pb2.Empty.SerializeToString,
            MADS__pb2.Empty.FromString,
            options, channel_credentials,
            insecure, call_credentials, compression, wait_for_ready, timeout, metadata)
