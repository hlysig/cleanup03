#!/bin/bash
git clone --recurse-submodules -b v1.34.0 https://github.com/grpc/grpc /var/local/git/grpc

cd /var/local/git/grpc

mkdir -p cmake/build && cd $_

cmake -DgRPC_INSTALL=ON -DgRPC_BUILD_TESTS=OFF ../..

make

make install