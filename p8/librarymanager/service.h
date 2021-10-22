#ifndef SERVICE_H
#define SERVICE_H

#include "borrower.h"
#include "book.h"

/* Records that a given book has been loaned to a given borrower. Returns TRUE
   if this succeeds, or FALSE if the book is already on loan (either to the
   same or a different borrower). */
int loanBook(Borrower* bor, Book* book);


/* Records that a given book is no longer on loan to a given borrower. Returns
   TRUE if this succeeds, or FALSE if the book is not on loan to that
   borrower. */
int returnBook(Borrower* bor, Book* book);

#endif