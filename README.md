# objectcube

## Setup

- Install Docker (https://www.docker.com/get-started)
- Install Docker Compose (https://docs.docker.com/compose/install/)

```
make compose
make compose-up
```

This starts two containers, with objectcube and PostgreSQL. ObjectCube api is exposed on port 5000 and PostgreSQL on port 5432.


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

Setup virtual Environment for API

```
make api
```

Build objectcube and objectcube Python wrapper.

```
make objectcube
```