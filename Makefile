.DEFAULT_GOAL := all

api:
	./scripts/boostrap-api.sh

update-proto-api: api
	./scripts/update-api-proto.sh

start-api: api
	src/api/.venv/bin/python src/api/api/wsgi.py

cli:
	./scripts/boostrap-cli.sh

update-proto-cli:
	./scripts/update-cli-proto.sh

core:
	mkdir -p build
	cd build; cmake ..; make

update-proto-core:
	./scripts/update-core-proto.sh

base-build-image:
	docker build -t hlysig/mads-grpc-builder:version1.0 -f containers/Dockerfile_base .

push-build-image:
	docker push hlysig/mads-grpc-builder:version1.0

database-image:
	docker build -t ocdb -f database/Dockerfile ./database

start-database: database-image
	docker run -d -p 5433:5432 ocdb:latest

all: core api

clean:
	rm -rf build
	rm -rf src/api/.venv
