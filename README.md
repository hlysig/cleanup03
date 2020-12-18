# MADS
...

## Project dependencies
To build MADS you need to install the following libraries and tools.

- [cmake](https://cmake.org/)
- [libpq](https://github.com/postgres/postgres/tree/master/src/interfaces/libpq)
- [libpqxx](https://github.com/jtv/libpqxx)
- [python3](https://www.python.org/)
- [gRPC](https://grpc.io/docs/languages/cpp/quickstart/)

### Install instructions for Ubuntu Linux

```
apt-get install -y cmake \
  build-essential \
  libpqxx-dev \
  libpq-dev \
  python3 \
  python3-venv \
  python3-dev \
  cmake \
  autoconf \
  libtool \
  pkg-config
```

For gRPC we refer to the [official
documentation](https://grpc.io/docs/languages/cpp/quickstart/) for installing
libgrpc and protoc.


### Install instructions for OSX

```
brew install autoconf \
  automake \
  libtool \
  pkg-config \
  libpq \
  libpqxx \
  zlib \
  pyenv
```

There are many ways to obtain Python, but here we use pyenv. Use approach that
suites you the best.

```
pyenv install 3.8.5
pyenv global 3.8.5
```

For gRPC we refer to the [official
documentation](https://grpc.io/docs/languages/cpp/quickstart/) for installing
libgrpc and protoc.

