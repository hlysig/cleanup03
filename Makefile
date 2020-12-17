.DEFAULT_GOAL := all

core:
	./scripts/update-core-proto.sh
	mkdir -p build
	cd build; cmake ..; make

api:
	./scripts/boostrap-api.sh
	./scripts/update-api-proto.sh

clean:
	rm -rf build
	rm -rf src/api/.venv

start-api: api
	src/api/.venv/bin/python src/api/api/wsgi.py

base-build-image:
	docker build -t hlysig/mads-grpc-builder:version1.0 -f Dockerfile_base .

push-build-image:
	docker push hlysig/mads-grpc-builder:version1.0

database-image:
	docker build -t ocdb -f database/Dockerfile ./database

start-database: database-image
	docker run -d -p 5433:5432 ocdb:latest

start-api: api
	src/api/.venv/bin/python src/api/api/wsgi.py

compose: base-docker-image
	docker-compose build

compose-up:
	docker-compose --env-file scripts/dockerenv up

all: core api
