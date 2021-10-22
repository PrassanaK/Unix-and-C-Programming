#ifndef BOOK_H
#define BOOK_H

#define MAX_STR_LENGTH 1000

typedef struct {
    char* title;
    char* author;
    int year;
    int isbn;
    int onLoan;
} Book;

Book* createBook(char* title, char* author, int year, int isbn);
void freeBook(Book* book);

#endif
