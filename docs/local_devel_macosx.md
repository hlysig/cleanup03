# Local development - macOSX
This document contains instructions on setting up MADS for local
development on macOS Big Sur 11.2.3.

MADS uses and has the dependencies to the following tools and libraries:

- [CMake](https://cmake.org/)
- [libpq](https://github.com/postgres/postgres/tree/master/src/interfaces/libpq)
- [libpqxx](https://github.com/jtv/libpqxx)
- [python3](https://www.python.org/)
- [gRPC](https://grpc.io/docs/languages/cpp/quickstart/)


We can install most of them with Homebrew.

```
brew install cmake libpq libpqxx
```

## Python3

One of the best ways to install Python is by using a tool named
[pyenv](https://github.com/pyenv/pyenv). With pyenv we can easily install
multiple versions of Python and change between them with ease without polluting
our system.

	brew install zlib pyenv

To successfully compile we must use zlib from Brew instead of the one provided
by Xcode. This is known bug in macOS 11.1. Export the following variables in
the shell before invoking pyenv.

	export LDFLAGS="-L/usr/local/opt/zlib/lib"
	export CPPFLAGS="-I/usr/local/opt/zlib/include"
	export PKG_CONFIG_PATH="/usr/local/opt/zlib/lib/pkgconfig"

Next we install Python 3.8.6 with pyenv.

	pyenv install 3.8.6
	pyenv global 3.8.6


Add the following lines to your bashrc or zshrc. This command loads the
globally set Python version to your path.

	if command -v pyenv 1>/dev/null 2>&1; then
	  eval "$(pyenv init -)"
	fi

Reload your shell and verify that Python was successfully installed
	
	➜  ~ which python
	/Users/hlysig/.pyenv/shims/python
	➜  ~ python
	Python 3.8.6 (default, Dec 18 2020, 14:34:11)
	[Clang 12.0.0 (clang-1200.0.32.28)] on darwin
	Type "help", "copyright", "credits" or "license" for more information.
	>>>


## gRPC
Currently, we depend on gRPC version 1.35.0. We install gRPC from source and
keep the compiled artifacts in `$HOME/.local`. Note that the location of gRPC
is important where we refer this location in our build scripts.


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
Downlad and install [Docker for mac][https://docs.docker.com/docker-for-mac/install/].

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

