#include <stdlib.h>

#include "service.h"
#include "boolean.h"

/* Records that a given book has been loaned to a given borrower. Returns TRUE
   if this succeeds, or FALSE if the book is already on loan (either to the
   same or a different borrower). */
int loanBook(Borrower* bor, Book* book) {
    int success = FALSE;

    if(!book->onLoan) {
        book->onLoan = TRUE;
        bor->numBooksBorrowed++;
        bor->booksBorrowed = (Book**)realloc(bor->booksBorrowed, bor->numBooksBorrowed * sizeof(Book*));
        bor->booksBorrowed[bor->numBooksBorrowed - 1] = book;
        success = TRUE;
    }

    return success;
}


/* Records that a given book is no longer on loan to a given borrower. Returns
   TRUE if this succeeds, or FALSE if the book is not on loan to that
   borrower. */
int returnBook(Borrower* bor, Book* book) {
    int success = FALSE;
    int i = 0;

    while(i < bor->numBooksBorrowed && bor->booksBorrowed[i] != book) {
        i++;
    }

    if(i < bor->numBooksBorrowed) {
        book->onLoan = FALSE;
        bor->numBooksBorrowed--;
        while(i < bor->numBooksBorrowed) {
            bor->booksBorrowed[i] = bor->booksBorrowed[i + 1];
            i++;
        }
        bor->booksBorrowed = (Book**)realloc(bor->booksBorrowed, bor->numBooksBorrowed * sizeof(Book*));

        success = TRUE;
    }

    return success;
}
