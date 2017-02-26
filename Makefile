all:
	rm -rf build
	mkdir build	
	mpicc mpi_hello_world.c -o build/mpi_hello_world

clean:
	rm -rf build

run:
	mpiexec -np 16 ./build/mpi_hello_world
