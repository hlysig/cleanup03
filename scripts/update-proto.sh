#!/bin/sh

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
PROTO_DIR="$SCRIPT_DIR/../src/proto"

cd "$SCRIPT_DIR"

function main {
  cd $PROTO_DIR
  protoc -I . --grpc_out=. --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` OC.proto
  protoc -I . --cpp_out=. OC.proto
}

main $@;


