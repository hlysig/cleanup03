#!/bin/bash

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

API_PROJECT_DIR="$SCRIPT_DIR/../src/api"

if [[ "$OSTYPE" == "darwin"* ]]; then
  export GRPC_PYTHON_BUILD_SYSTEM_ZLIB=true
fi

function update_python_proto {
  pushd "$API_PROJECT_DIR"
  .venv/bin/python -m grpc_tools.protoc -I../proto --python_out=api --grpc_python_out=api ../proto/OC.proto
  popd
}

function main {
  update_python_proto
}

main "$@"

