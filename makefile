# -*- Makefile -*-

all: isort txtfind

txtfind: txtfind.o maintxtfind.o
	gcc -Wall -fPIC -o txtfind maintxtfind.o txtfind.o

mainTXT.o: maintxtfind.c txtfind.h
	gcc -Wall -c maintxtfind.c

txtfind.o: txtfind.c txtfind.h
	gcc -Wall -fPIC -c txtfind.c	

isort: isort.o mainisort.o
	gcc -Wall -fPIC -o isort mainisort.o isort.o

main.o: mainisort.c isort.h
	gcc -Wall -c mainisort.c

isort.o: isort.c isort.h
	gcc -Wall -fPIC -c isort.c	

.PHONY: clean all 

clean:
	rm -f *.o isort txtfind