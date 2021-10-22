#ifndef BORROWER_H
#define BORROWER_H

#include "book.h"

typedef struct {
    int id;
    char* name;
    Book** booksBorrowed;
    int numBooksBorrowed;
} Borrower;


Borrower* createBorrower(char* name);
void freeBorrower(Borrower* bor);


#endif
