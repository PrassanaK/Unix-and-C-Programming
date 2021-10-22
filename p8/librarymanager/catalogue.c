#include <stdlib.h>
#include <stdio.h>
#include "catalogue.h"
#include "book.h"
#include "boolean.h"
#include "util.h"

Catalogue* createCatalogue() {
    Catalogue* cat = (Catalogue*)malloc(sizeof(Catalogue));
    cat->books = NULL;
    cat->numBooks = 0;
    return cat;
}


int loadCatalogue(Catalogue* cat, char* filename) {
    int i;
    int success = FALSE;
    int eof = TRUE;
    char title[MAX_STR_LENGTH];
    char author[MAX_STR_LENGTH];
    int year, isbn;

    FILE* file = fopen(filename, "r");

    if(file != NULL) {
        /* Clear the existing catalogue entries. */
        for(i = 0; i < cat->numBooks; i++) {
            freeBook(cat->books[i]);
        }

        /* Read the new catalogue. */
        fscanf(file, "%d", &cat->numBooks);
        discardExcessInput(file);
        cat->books = (Book**)malloc(cat->numBooks * sizeof(Book*));

        i = 0;
        do {
            fileReadLine(file, title, MAX_STR_LENGTH);
            fileReadLine(file, author, MAX_STR_LENGTH);
            fscanf(file, "%d, %d", &year, &isbn);
            discardExcessInput(file);

            if(feof(file)) {
                eof = TRUE;
            }
            else {
                cat->books[i] = createBook(title, author, year, isbn);
                i++;
            }
        }
        while(!eof);

        success = !ferror(file);
        fclose(file);
    }

    return success;
}


int saveCatalogue(Catalogue* cat, char* filename) {
    int success = FALSE;
    int i;
    FILE* file = fopen(filename, "w");

    if(file != NULL) {
        fprintf(file, "%d\n", cat->numBooks);

        for(i = 0; i < cat->numBooks; i++) {
            fprintf(file, "%s\n%s\n%d, %d\n",
                cat->books[i]->title,
                cat->books[i]->author,
                cat->books[i]->year,
                cat->books[i]->isbn);
        }

        success = !ferror(file);
        fclose(file);
    }

    return success;
}


Book* getBook(Catalogue* cat, int isbn) {
    Book* book = NULL;
    int i = 0;

    while(i < cat->numBooks && cat->books[i]->isbn != isbn) {
        i++;
    }

    if(i < cat->numBooks) {
        book = cat->books[i];
    }

    return book;
}


/* Increase the size of the books array in the catalogue by 1, and place a new
   book in the last element. */
void addBook(Catalogue* cat, Book* book) {
    cat->numBooks++;
    cat->books = (Book**)realloc(cat->books, cat->numBooks * sizeof(Book*));
    cat->books[cat->numBooks - 1] = book;
}


/* Remove and return the book at a given array index, shortening the array by
   1. */
Book* deleteBook(Catalogue* cat, int isbn) {
    Book* book = NULL;
    int i = 0;

    while(i < cat->numBooks && cat->books[i]->isbn != isbn) {
        i++;
    }

    if(i < cat->numBooks) {
        book = cat->books[i];

        cat->numBooks--;

        while(i < cat->numBooks) {
            cat->books[i] = cat->books[i + 1];
            i++;
        }

        cat->books = (Book**)realloc(cat->books, cat->numBooks * sizeof(Book*));
    }

    return book;
}


void freeCatalogue(Catalogue* cat) {
    int i;
    for(i = 0; i < cat->numBooks; i++) {
        freeBook(cat->books[i]);
    }
    free(cat->books);
    free(cat);
}

