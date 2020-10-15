FROM ubuntu:20.04

WORKDIR /objectcube

RUN apt-get update && apt-get upgrade -y
RUN DEBIAN_FRONTEND="noninteractive" apt-get -y install tzdata

RUN apt-get install -y cmake \
    build-essential \
    libpqxx-dev \
    libpq-dev \
    python3 \
    python3-venv \
    python3-dev \
    libboost-all-dev

ADD src src
ADD CMakeLists.txt CMakeLists.txt
ADD Makefile Makefile

RUN make objectcube
RUN make api

EXPOSE 5000
CMD src/api/bin/run.sh
