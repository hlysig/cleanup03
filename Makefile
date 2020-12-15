.DEFAULT_GOAL := default

update-proto:
	./scripts/update-proto.sh

default: update-proto
	mkdir -p build
	cd build; cmake ..; make

api:
	cd src/api; make bootstrap

database-docker:
	docker build -t ocdb -f database/Dockerfile ./database

start-database-docker: database-docker
	docker run -d -p 5433:5432 ocdb:latest

compose:
	docker-compose build

compose-up:
	docker-compose up

all: objectcube api database-docker
