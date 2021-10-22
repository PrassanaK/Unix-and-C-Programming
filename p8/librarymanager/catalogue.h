#ifndef CATALOGUE_H
#define CATALOGUE_H

#include "book.h"

typedef struct {
    Book** books;
    int numBooks;
} Catalogue;

Catalogue* createCatalogue();
int loadCatalogue(Catalogue* cat, char* filename);
int saveCatalogue(Catalogue* cat, char* filename);
Book* getBook(Catalogue* cat, int isbn);
void addBook(Catalogue* cat, Book* book);
Book* deleteBook(Catalogue* cat, int isbn);
void freeCatalogue(Catalogue* cat);

#endif
