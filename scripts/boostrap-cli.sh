#!/bin/bash
set -euo pipefail

# This script bootstraps the MADS api project (src/api). It is responsible for
# creating a Python 3 virtualenv, if not found, and pip install all required
# dependencies described in the projects requirements.txt file.  This script is
# path agnostic so it can be executed directly from the git root.
#
# usage: ./scripts/bootstrap.api
#
# Notes: For OSX 11.1 we have to do a workaround for zlib for now. Thus, when
# installing grpc dependencies we export a flag to build it locally when
# installing the package. This has impact on install time and should be removed
# when zlib issues have been resolved for OSX 11.1.

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
API_PROJECT_DIR="$SCRIPT_DIR/../src/cli"
source "$SCRIPT_DIR/common.sh"

if [[ "$OSTYPE" == "darwin"* ]]; then
  export GRPC_PYTHON_BUILD_SYSTEM_ZLIB=true
fi

function setup_venv {
  command_exists git || {
    fmt_error "git is not installed"
      exit 1
    }

  pushd "$API_PROJECT_DIR"
  if [ ! -d ".venv" ]; then
    fmt_info "No virtualenv found in ${API_PROJECT_DIR} creating.."
    python3 -m venv .venv
  fi
  fmt_info "Installing dependencies from requirements.txt for MADS api"
  .venv/bin/pip install -r requirements.txt
  fmt_info "MADS api is ready"
  popd
}

function main {
  fmt_info "Bootstrapping MADS cli"
  setup_venv
}

main "$@"

