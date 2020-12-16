.DEFAULT_GOAL := default

bootstrap-api:
	./scripts/boostrap-api.sh

update-proto-core:
	./scripts/update-core-proto.sh

update-api-proto: bootstrap-api
	./scripts/update-api-proto.sh

core: update-proto-core
	mkdir -p build
	cd build; cmake ..; make

api: update-api-proto

base-docker-image:
	docker build -t grpc_base -f Dockerfile_base .

database-docker:
	docker build -t ocdb -f database/Dockerfile ./database

start-database-docker: database-docker
	docker run -d -p 5433:5432 ocdb:latest

compose: base-docker-image
	docker-compose build

compose-up:
	docker-compose --env-file scripts/env up

all: objectcube api database-docker
