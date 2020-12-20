# MADS
...

## Project dependencies
To build MADS you need to install the following libraries and tools.

- [CMake](https://cmake.org/)
- [libpq](https://github.com/postgres/postgres/tree/master/src/interfaces/libpq)
- [libpqxx](https://github.com/jtv/libpqxx)
- [python3](https://www.python.org/)
- [gRPC](https://grpc.io/docs/languages/cpp/quickstart/)

## Install instructions for Ubuntu Linux

```
apt-get install -y cmake \
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

For gRPC we refer to the [official
documentation](https://grpc.io/docs/languages/cpp/quickstart/) for installing
libgrpc and protoc.


## Install instructions for macOS

This section contain instructions on how to setup local development environment
for contributing and building MADS on Apple macOS. The following steps were
  performed on Apple macOS 11.1 (Big Sur). Before you follow the instructions
  you must setup and update [Homebrew](https://brew.sh/) and the Xcode command
  line tools on your system.
To successfully build MAST we must set up the following tools and libraries.

- [Python 3](https://www.python.org/)
- [zlib](https://zlib.net/)
- [libpq](https://postgrespro.com/docs/postgresql/10/libpq)
- [libpqxx](https://github.com/jtv/libpqxx)
- [CMake](https://github.com/jtv/libpqxx)
- [gRPC](https://grpc.io/)


## Python3

In this tutorial we install Python3 with a tool named
[pyenv](https://github.com/pyenv/pyenv). With pyenv we can easily install
multiple versions of Python and change between them with ease.

	brew install zlib pyenv

To successfully compile we must use zlib from Brew instead of the one provided
by Xcode. This is known bug in macOS 11.1. Export the following variables in
the shell that before invoking pyenv.

	export LDFLAGS="-L/usr/local/opt/zlib/lib"
	export CPPFLAGS="-I/usr/local/opt/zlib/include"
	export PKG_CONFIG_PATH="/usr/local/opt/zlib/lib/pkgconfig"

Next we install Python 3.8.6 with pyenv.

	pyenv install 3.8.6
	pyenv global 3.8.6


Then add the following lines to your bashrc or zshrc. This command loads the
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


## libpq and libpqxx

Next we install libpq and libpqxx through Homebrew.

	brew install libpq libpqxx

## gRPC
	
Next we need to instal gRPC.

	brew install autoconf automake libtool pkg-config cmake

	export MY_INSTALL_DIR=$HOME/.local
	mkdir -p $MY_INSTALL_DIR
	
	// Add the following to your path
	export PATH="$PATH:$MY_INSTALL_DIR/bin"
	
	brew install autoconf automake libtool pkg-config cmake
	
	mkdir ~/repos; cd $_;
	git clone --recurse-submodules -b v1.34.0 https://github.com/grpc/grpc
	
	cd grpc
	
	mkdir -p cmake/build; cd $_

	cmake -DgRPC_INSTALL=ON -DgRPC_BUILD_TESTS=OFF -DCMAKE_INSTALL_PREFIX=$MY_INSTALL_DIR ../..
	$ make -j
	$ make install
	$ popd
		
## docker

Download and install Docker Desktop for mac from
[https://hub.docker.com/editions/community/docker-ce-desktop-mac/](https://hub.docker.com/editions/community/docker-ce-desktop-mac/).

## building core

At this point your system should be set up to build MADS. Let's start with building MADS core.

	mkdir build; cd $_
	cmake ..
	make

We have a `make` target which does this for us.

	make core
	
Built artifacts are placed under `build/bin` and `build/lib`.

We can also start core (MADS gRPC server) with Docker.

	docker-compose build
	docker-compose up

Two ports are exposed, 26026 for gRPC server and 5432 for PostgreSQL.

