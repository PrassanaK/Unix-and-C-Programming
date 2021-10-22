#ifndef BORROWER_LIST_H
#define BORROWER_LIST_H

#include "borrower.h"

typedef struct {
    Borrower** borrowers;
    int numBorrowers;
    int nextId;
} BorrowerList;


BorrowerList* createBorrowerList();
int loadBorrowerList(BorrowerList* blist, char* filename);
int saveBorrowerList(BorrowerList* blist, char* filename);
Borrower* getBorrower(BorrowerList* blist, int id);
void addBorrower(BorrowerList* blist, Borrower* bor);
Borrower* deleteBorrower(BorrowerList* blist, int id);
void freeBorrowerList(BorrowerList* blist);

#endif
