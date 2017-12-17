all:	./bin/main.o 
	g++ ./bin/main.o -o ./bin/lx

./bin/main.o:	
	g++ -c ./src/main.c -I./include -o ./bin/main.o



main.c:
	vim ./src/main.c
test.h:
	vim ./include/test.h
testcase.h:
	vim ./include/testcase.h

do:
	make clean;make;make run

run:
	echo "\033[;31mstart lx :\033[0m";clear;./bin/lx
look:
	ls -l ./bin
clean:
	rm -rf ./bin/*o
