objectcube:
	mkdir -p build
	cd build; cmake ..; make

api:
	cd src/api; make bootstrap
