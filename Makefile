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

database-docker:
	docker build -t ocdb -f database/Dockerfile ./database

start-database-docker: database-docker
	docker run -d -p 5433:5432 ocdb:latest

compose:
	docker-compose build

compose-up:
	docker-compose up

all: objectcube api database-docker
