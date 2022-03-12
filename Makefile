output: main.o lib.o
	gcc main.o lib.o -o output 
main.o: main.c
	gcc -c main.c
lib.o: lib.c
	gcc -c lib.c