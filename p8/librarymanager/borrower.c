#include <stdlib.h>
#include <string.h>

#include "borrower.h"
#include "boolean.h"

Borrower* createBorrower(char* name) {
    int nameChars = strlen(name) + 1;     
    Borrower* bor = (Borrower*)malloc(sizeof(Borrower));

    bor->name = (char*)malloc(nameChars * sizeof(char));
    strncpy(name, bor->name, nameChars);
    bor->id = 0;

    bor->booksBorrowed = NULL;
    bor->numBooksBorrowed = 0;

    return bor;
}


void freeBorrower(Borrower* bor) {
    int i;
    for(i = 0; i < bor->numBooksBorrowed; i++) {
        bor->booksBorrowed[i]->onLoan = FALSE;
    }
    free(bor->booksBorrowed);
    free(bor->name);
    free(bor);
}
