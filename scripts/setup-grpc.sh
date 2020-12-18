#!/bin/bash
set -euo pipefail

# This script is a setup script for GRPC for Ubuntu 20.04. It is used
# in the base build container creation. This script should not be
# executed on users/dev machines.

GRPC_VERSION="v1.34.0"

git clone --recurse-submodules -b "$GRPC_VERSION" https://github.com/grpc/grpc /var/local/git/grpc

cd /var/local/git/grpc

mkdir -p cmake/build && cd $_
cmake -DgRPC_INSTALL=ON -DgRPC_BUILD_TESTS=OFF ../..

make
make install

