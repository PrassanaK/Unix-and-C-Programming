#include <stdio.h>
#include <stdlib.h>

#include "borrowerlist.h"
#include "boolean.h"
#include "util.h"

BorrowerList* createBorrowerList() {
    BorrowerList* blist = (BorrowerList*)malloc(sizeof(BorrowerList));
    blist->borrowers = NULL;
    blist->numBorrowers = 0;
    blist->nextId = 1;
    return blist;
}

int loadBorrowerList(BorrowerList* blist, char* filename) {
    int i;
    int success = FALSE;
    int eof = FALSE;
    int id;
    int maxId = 0;
    char name[MAX_STR_LENGTH];

    FILE* file = fopen(filename, "r");

    if(file != NULL) {
        /* Clear the existing borrower list entries. */
        for(i = 0; i < blist->numBorrowers; i++) {
            freeBorrower(blist->borrowers[i]);
        }

        /* Read the new catalogue. */
        fscanf(file, "%d", &blist->numBorrowers);
        discardExcessInput(file);
        blist->borrowers = (Borrower**)malloc(blist->numBorrowers * sizeof(Borrower*));

        i = 0;
        do {
            fscanf(file, "%d ", &id);
            fileReadLine(file, name, MAX_STR_LENGTH);

            if(feof(file)) {
                eof = TRUE;
            }
            else {
                blist->borrowers[i] = createBorrower(name);
                blist->borrowers[i]->id = id;
                if(maxId < id) {
                    maxId = id;
                }
                i++;
            }
        }
        while(!eof);

        success = !ferror(file);
        fclose(file);

        blist->nextId = maxId + 1;
    }

    return success;
}


int saveBorrowerList(BorrowerList* blist, char* filename) {
    int success = FALSE;
    int i;
    FILE* file = fopen(filename, "w");

    if(file != NULL) {
        fprintf(file, "%d\n", blist->numBorrowers);

        for(i = 0; i < blist->numBorrowers; i++) {
            fprintf(file, "%d %s\n",
                blist->borrowers[i]->id,
                blist->borrowers[i]->name);
        }

        success = !ferror(file);
        fclose(file);
    }

    return success;
}

Borrower* getBorrower(BorrowerList* blist, int id) {
    Borrower* borrower = NULL;
    int i = 0;

    while(i < blist->numBorrowers && blist->borrowers[i]->id != id) {
        i++;
    }

    if(i < blist->numBorrowers) {
        borrower = blist->borrowers[i];
    }

    return borrower;
}


/* Increase the size of the borrowers array in the list by 1, and place a new
   borrower in the last element. */
void addBorrower(BorrowerList* blist, Borrower* bor) {
    blist->numBorrowers++;
    blist->borrowers = (Borrower**)realloc(blist->borrowers, blist->numBorrowers * sizeof(Borrower*));
    blist->borrowers[blist->numBorrowers - 1] = bor;

    bor->id = blist->nextId;
    blist->nextId++;
}


/* Remove and return the borrower at a given array index, shortening the array
   by 1. */
Borrower* deleteBorrower(BorrowerList* blist, int id) {
    Borrower* bor = NULL;
    int i = 0;

    while(i < blist->numBorrowers && blist->borrowers[i]->id != id) {
        i++;
    }

    if(i < blist->numBorrowers) {
        bor = blist->borrowers[i];

        blist->numBorrowers--;

        while(i < blist->numBorrowers) {
            blist->borrowers[i] = blist->borrowers[i + 1];
            i++;
        }

        blist->borrowers = (Borrower**)realloc(blist->borrowers, blist->numBorrowers * sizeof(Borrower*));
    }

    return bor;
}


void freeBorrowerList(BorrowerList* blist) {
    int i;
    for(i = 0; i < blist->numBorrowers; i++) {
        freeBorrower(blist->borrowers[i]);
    }
    free(blist->borrowers);
    free(blist);
}
