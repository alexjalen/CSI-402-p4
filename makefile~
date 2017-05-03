p4: main.o error.o rootName.o readFile.o passOne.o passTwo.o prototypes.h headers.h
	gcc main.o rootName.o readFile.o passOne.o passTwo.o error.o -o p4
main.o: main.c prototypes.h headers.h
	gcc -c main.c
error.o: error.c prototypes.h headers.h
	gcc -c error.c
rootName.o: rootName.c prototypes.h headers.h
	gcc -c rootName.c
readFile.o: readFile.c prototypes.h headers.h
	gcc -c readFile.c
passOne.o: passOne.c prototypes.h headers.h
	gcc -c passOne.c
passTwo.o: passTwo.c prototypes.h headers.h
	gcc -c passTwo.c
clean:
	rm -f *.o core p4
