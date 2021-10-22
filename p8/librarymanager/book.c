#include <stdlib.h>
#include <string.h>

#include "book.h"
#include "boolean.h"

Book* createBook(char* title, char* author, int year, int isbn) {
    Book* book = (Book*)malloc(sizeof(Book));

    /* Allocate just enough space for the title and author */
    book->title = (char*)malloc((strlen(title) + 1) * sizeof(char));
    book->author = (char*)malloc((strlen(author) + 1) * sizeof(char));

    /* Set initial values */
    strcpy(book->title, title);
    strcpy(book->author, author);
    book->year = year;
    book->isbn = isbn;
    book->onLoan = FALSE;

    return book;
}

void freeBook(Book* book) {
    free(book->title);
    free(book->author);
    free(book);
}
