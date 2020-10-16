# objectcube

This repository is WIP for cleaning up the original ObjectCube code owned by
Dr. Björn Þór Jónsson Et al.

## Running Docker locally

Install `docker-compose`

```
sudo curl -L "https://github.com/docker/compose/releases/download/1.26.0/docker-compose-$(uname -s)-$(uname -m)" -o /usr/local/bin/docker-compose
sudo chmod +x /usr/local/bin/docker-compose
```

## Local development setup

This section describe setup instructions for dependencies for local
development.

## Ubuntu Linux

```
apt update && apt upgrade

apt install -y cmake \
  build-essential \
  libpqxx-dev \
  libpq-dev \
  python3 \
  python3-venv \
  python3-dev \
  libboost-all-dev
```

To setup virtual Environment for API

```
make api
```

To build object cube and objectcube Python wrapper.

```
make objectcube
```

## OSX Catalina

```
brew install cmake
brew install xmlto
git clone https://github.com/jtv/libpqxx.git
cd libpqxx
./configure
make
make install
brew install boost-python3
```
