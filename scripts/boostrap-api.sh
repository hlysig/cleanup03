#!/bin/bash

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

API_PROJECT_DIR="$SCRIPT_DIR/../src/api"

if [[ "$OSTYPE" == "darwin"* ]]; then
  export GRPC_PYTHON_BUILD_SYSTEM_ZLIB=true
fi

function setup_venv {
  pushd "$API_PROJECT_DIR"
  if [ ! -d ".venv" ]; then
    python3 -m venv .venv
  fi
  .venv/bin/pip install -r requirements.txt
  popd
}

function main {
  setup_venv
}

main "$@"

