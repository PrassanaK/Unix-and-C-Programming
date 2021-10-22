CC = gcc
CFLAGS = -Wall -ansi -pedantic -g
OBJ = librarymanager.o menusystem.o service.o catalogue.o book.o borrowerlist.o borrower.o util.o
EXEC = librarymanager

$(EXEC) : $(OBJ)
	gcc -o $(EXEC) $(OBJ)

librarymanger.o : librarymanger.c menusystem.h catalogue.h book.h borrowerlist.h borrower.h
	gcc $(CFLAGS) -c librarymanger.c

menusystem.o : menusystem.c menusystem.h catalogue.h book.h borrowerlist.h borrower.h util.h
	gcc $(CFLAGS) -c menusystem.c

service.o : service.c service.h book.h borrower.h boolean.h
	gcc $(CFLAGS) -c service.c

catalogue.o : catalogue.c catalogue.h book.h borrower.h boolean.h util.h
	gcc $(CFLAGS) -c catalogue.c

book.o : book.c book.h boolean.h
	gcc $(CFLAGS) -c book.c

borrowerlist.o : borrowerlist.c borrowerlist.h borrower.h book.h boolean.h
	gcc $(CFLAGS) -c borrowerlist.c

borrower.o : borrower.c borrower.h book.h boolean.h
	gcc $(CFLAGS) -c borrower.c

util.o: util.c util.h
	gcc $(CFLAGS) -c util.c

clean :
	rm -f $(EXEC) $(OBJ)
