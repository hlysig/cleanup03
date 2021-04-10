# Local development - Ubuntu
This document contains instructions on setting up MADS for local
development on Ubuntu 20.04.2 LTS with kernel 5.8.0-48-generic.

MADS uses and has the dependencies to the following tools and libraries:

- [CMake](https://cmake.org/)
- [libpq](https://github.com/postgres/postgres/tree/master/src/interfaces/libpq)
- [libpqxx](https://github.com/jtv/libpqxx)
- [python3](https://www.python.org/)
- [gRPC](https://grpc.io/docs/languages/cpp/quickstart/)

We can install most of them through the Advanced Package Tool.

```
sudo apt-get install -y cmake \
  build-essential \
  libpqxx-dev \
  libpq-dev \
  python3 \
  python3-venv \
  python3-dev \
  autoconf \
  libtool \
  pkg-config
```

Currently, we depend on gRPC version 1.35.0. We install gRPC from source
and keep the compiled artifacts in `$HOME/.local`. Note that the location
of gRPC is important where we refer this location in our build scripts.


```
export GRPC_CLONE_DIR="$HOME/.tmp.grpc"
export GRPC_INSTALL_DIR=$HOME/.local

mkdir -p "$GRPC_CLONE_DIR"
mkdir -p "$GRPC_INSTALL_DIR"

cd "$GRPC_CLONE_DIR"
git clone --recurse-submodules -b v1.35.0 https://github.com/grpc/grpc
cd grpc

mkdir -p cmake/build; cd $_
cmake -DgRPC_INSTALL=ON -DgRPC_BUILD_TESTS=OFF -DCMAKE_INSTALL_PREFIX=$GRPC_INSTALL_DIR ../..
make
make install

cd
rm -rf "$GRPC_CLONE_DIR"

```

Add the following lines to your shell configuration file (.bashrc, .zshrc, etc)

```
export GRPC_INSTALL_DIR=$HOME/.local
export PATH="$GRPC_INSTALL_DIR/bin:$PATH"
```

## Docker

To setup Docker engine on Ubuntu execute the following commands into your terminal.

```
sudo apt install apt-transport-https ca-certificates curl software-properties-common
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
sudo add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu focal stable"
sudo apt update
sudo apt install docker-ce
sudo usermod -aG docker ${USER}
```

We add the current user to the `docker` group to allow them to interact with
Docker without root. For this to wok you must log-in again or `su` to apply the
new group membership.

```
su - ${USER}
```

We use `docker-compose` for local development.
 
```
sudo curl -L "https://github.com/docker/compose/releases/download/1.29.0/docker-compose-$(uname -s)-$(uname -m)" -o /usr/local/bin/docker-compose
sudo chmod +x /usr/local/bin/docker-compose
```


## Building core
At this point your system should be set up to build MADS. Let's start with
building MADS core. From the root directory of the project, type in the
following.

	mkdir build; cd $_
	cmake -DCMAKE_PREFIX_PATH=$GRPC_INSTALL_DIR ..
	make

We have a `make` target which does this for us.

	make core
	
Built artifacts are placed under `build/bin` and `build/lib`.

We can also start core (MADS gRPC server) with Docker.

	docker-compose build
	docker-compose up

Two ports are exposed, 26026 for gRPC server and 5432 for PostgreSQL.

To build MADS Python API run the following make target.

        make api

The api can then be started with make target named `start-api`.

        make start-api

