#include <stdio.h>
#include <stdlib.h>

#include "menusystem.h"
#include "service.h"
#include "catalogue.h"
#include "book.h"
#include "borrowerlist.h"
#include "borrower.h"
#include "util.h"
#include "boolean.h"

#define MAX_FILENAME_LENGTH 1000

/* The following constants define the keys used to access various menu
   options. */
#define LOAD 'l'
#define SAVE 's'
#define ADD '+'
#define DELETE '-'
#define LOAN_BOOK 'o'
#define RETURN_BOOK 'r'
#define LIST_BOOKS 'k'
#define LIST_BORROWERS 'w'
#define CATALOGUE_MENU 'c'
#define BORROWER_MENU 'b'
#define QUIT 'q'


static void catalogueMenu(Catalogue* cat);
static void borrowerMenu(BorrowerList* blist);
static void menuLoanBook(Catalogue* cat, BorrowerList* blist);
static void menuReturnBook(Catalogue* cat, BorrowerList* blist);

static void menuLoadCatalogue(Catalogue* cat);
static void menuSaveCatalogue(Catalogue* cat);
static void menuAddBook(Catalogue* cat);
static void menuDeleteBook(Catalogue* cat);
static void menuListBooks(Catalogue* cat);

static void menuLoadBorrowerList(BorrowerList* blist);
static void menuSaveBorrowerList(BorrowerList* blist);
static void menuAddBorrower(BorrowerList* blist);
static void menuDeleteBorrower(BorrowerList* blist);
static void menuListBorrowers(BorrowerList* blist);


/* Executes the library manager's menu system, given a catalogue and borrower
   list. (This is the only function accessible from other .c files.) */
void menuSystem(Catalogue* cat, BorrowerList* blist)
{
    char option;
    int quit = FALSE;

    printf("Library Manager, v1.0\n");
    do {
        printf("\nMain Menu\n----\n");
        printf(" %c   Loan book\n", LOAN_BOOK);
        printf(" %c   Return book\n", RETURN_BOOK);
        printf(" %c   List books\n", LIST_BOOKS);
        printf(" %c   List borrowers\n", LIST_BORROWERS);
        printf(" %c   Catalogue menu\n", CATALOGUE_MENU);
        printf(" %c   Borrower menu\n", BORROWER_MENU);
        printf(" %c   Quit\n", QUIT);
        printf("----\n");

        option = readChar("Enter an option: ");
        printf("\n");

        switch(option) {
            case LOAN_BOOK:
                menuLoanBook(cat, blist);
                break;

            case RETURN_BOOK:
                menuReturnBook(cat, blist);
                break;

            case LIST_BOOKS:
                menuListBooks(cat);
                break;

            case LIST_BORROWERS:
                menuListBorrowers(blist);
                break;

            case CATALOGUE_MENU:
                catalogueMenu(cat);
                break;

            case BORROWER_MENU:
                borrowerMenu(blist);
                break;

            case QUIT:
                quit = TRUE;
                break;

            default:
                printf("Unrecognised option: %c\n", option);
        }

    } while(!quit);
}


/* Displays the catalogue sub-menu (showing options to manipulate the library's
   collection of books). */
static void catalogueMenu(Catalogue* cat) {
    char option;
    int quit = FALSE;

    do {
        printf("\nCatalogue Menu\n----\n");
        printf(" %c   Load catalogue\n", LOAD);
        printf(" %c   Save catalogue\n", SAVE);
        printf(" %c   Add book\n", ADD);
        printf(" %c   Delete book\n", DELETE);
        printf(" %c   Main menu\n", QUIT);
        printf("----\n");

        option = readChar("Enter an option: ");
        printf("\n");

        switch(option) {
            case LOAD:
                menuLoadCatalogue(cat);
                break;

            case SAVE:
                menuSaveCatalogue(cat);
                break;

            case ADD:
                menuAddBook(cat);
                break;

            case DELETE:
                menuDeleteBook(cat);
                break;

            case QUIT:
                quit = TRUE;
                break;

            default:
                printf("Unrecognised option: %c\n", option);
        }
    } while(!quit);
}


/* Displays the borrower sub-menu, showing options to manipulate the library's
   borrower records). */
static void borrowerMenu(BorrowerList* blist) {
    char option;
    int quit = FALSE;

    do {
        printf("\nBorrower Menu\n----\n");
        printf(" %c   Load borrower list\n", LOAD);
        printf(" %c   Save borrower list\n", SAVE);
        printf(" %c   Add borrower\n", ADD);
        printf(" %c   Delete borrower\n", DELETE);
        printf(" %c   Main menu\n", QUIT);
        printf("----\n");

        option = readChar("Enter an option: ");
        printf("\n");

        switch(option) {
            case LOAD:
                menuLoadBorrowerList(blist);
                break;

            case SAVE:
                menuSaveBorrowerList(blist);
                break;

            case ADD:
                menuAddBorrower(blist);
                break;

            case DELETE:
                menuDeleteBorrower(blist);
                break;

            case QUIT:
                quit = TRUE;
                break;

            default:
                printf("Unrecognised option: %c\n", option);
        }
    } while(!quit);
}


static void menuLoanBook(Catalogue* cat, BorrowerList* blist) {
    Borrower* borrower;
    Book* book;

    borrower = getBorrower(blist, readInt("Enter borrower ID: "));

    if(borrower == NULL) {
        printf("No borrower with that ID was found.\n");
    }
    else {
        book = getBook(cat, readInt("Enter ISBN of book to borrow: "));

        if(book == NULL) {
            printf("No book with that ISBN was found.\n");
        }
        else {
            if(loanBook(borrower, book)) {
                printf("Book loaned.\n");
            }
            else {
                printf("That book is already on loan!\n");
            }
        }
    }
}


static void menuReturnBook(Catalogue* cat, BorrowerList* blist) {
    Borrower* borrower;
    Book* book;

    borrower = getBorrower(blist, readInt("Enter borrower ID: "));

    if(borrower == NULL) {
        printf("No borrower with that ID was found.\n");
    }
    else {
        book = getBook(cat, readInt("Enter ISBN of book to return: "));

        if(book == NULL) {
            printf("No book with that ISBN was found.\n");
        }
        else {
            if(returnBook(borrower, book)) {
                printf("Book returned.\n");
            }
            else {
                printf("That book is not on loan to that borrower!\n");
            }
        }
    }
}


static void menuLoadCatalogue(Catalogue* cat) {
    char filename[MAX_FILENAME_LENGTH];

    readLine("Enter name of catalogue file to load: ",
             filename, MAX_FILENAME_LENGTH);

    printf("Loading catalogue '%s'...\n", filename);
    if(loadCatalogue(cat, filename)) {
        printf("Success.\n");
    }
    else {
        perror("Unable to load catalogue");
    }
}


static void menuSaveCatalogue(Catalogue* cat) {
    char filename[MAX_FILENAME_LENGTH];

    readLine("Enter filename to store catalogue: ",
             filename, MAX_FILENAME_LENGTH);

    printf("Saving catalogue as '%s'...\n", filename);
    if(saveCatalogue(cat, filename)) {
        printf("Success.\n");
    }
    else {
        perror("Unable to save catalogue");
    }
}


static void menuAddBook(Catalogue* cat) {
    char title[MAX_STR_LENGTH];
    char author[MAX_STR_LENGTH];
    int pubDate;
    int isbn;
    Book* book;

    readLine("Enter title: ", title, MAX_STR_LENGTH);
    readLine("Enter author: ", author, MAX_STR_LENGTH);
    pubDate = readInt("Enter publication date: ");
    isbn = readInt("Enter ISBN: ");

    book = createBook(title, author, pubDate, isbn);
    addBook(cat, book);
}


static void menuDeleteBook(Catalogue* cat) {
    Book* book;
    int isbn = readInt("Enter ISBN of book to delete: ");

    book = deleteBook(cat, isbn);
    if(book != NULL) {
        printf("\"%s\", by %s (%d) has been deleted from the catalogue.\n",
            book->title,
            book->author,
            book->year);
        freeBook(book);
    }
    else {
        printf("No book with that ISBN was found.\n");
    }
}


static void menuListBooks(Catalogue* cat) {
    int i;
    char* onLoanStr;

    printf("Title                           Author                Year  ISBN        On loan\n");
    printf("---------------------------------------------------------------------------------\n");
    for(i = 0; i < cat->numBooks; i++) {
        onLoanStr = "";
        if(cat->books[i]->onLoan) {
            onLoanStr = "yes";
        }

        printf("%-30s  %-20s  %d  %-10d  %s\n",
            cat->books[i]->title,
            cat->books[i]->author,
            cat->books[i]->year,
            cat->books[i]->isbn,
            onLoanStr);
    }
    printf("---------------------------------------------------------------------------------\n");
}


static void menuLoadBorrowerList(BorrowerList* blist) {
    char filename[MAX_FILENAME_LENGTH];

    readLine("Enter name of borrower list file to load: ",
             filename, MAX_FILENAME_LENGTH);

    printf("Loading borrower list '%s'...\n", filename);
    if(loadBorrowerList(blist, filename)) {
        printf("Success.\n");
    }
    else {
        perror("Unable to load borrower list");
    }
}

static void menuSaveBorrowerList(BorrowerList* blist) {
    char filename[MAX_FILENAME_LENGTH];

    readLine("Enter filename to store borrower list: ",
             filename, MAX_FILENAME_LENGTH);

    printf("Saving borrower list as '%s'...\n", filename);
    if(saveBorrowerList(blist, filename)) {
        printf("Success.\n");
    }
    else {
        perror("Unable to save borrower list");
    }
}


static void menuAddBorrower(BorrowerList* blist) {
    char name[MAX_STR_LENGTH];
    Borrower* borrower;

    readLine("Enter name: ", name, MAX_STR_LENGTH);

    borrower = createBorrower(name);
    addBorrower(blist, borrower);
}


static void menuDeleteBorrower(BorrowerList* blist) {
    Borrower* bor;
    int id = readInt("Enter ID of borrower to delete: ");

    bor = deleteBorrower(blist, id);
    if(bor != NULL) {
        printf("%s has been deleted from borrower list.\n", bor->name);
        freeBorrower(bor);
    }
    else {
        printf("No borrower with that ID was found.\n");
    }
}


static void menuListBorrowers(BorrowerList* blist) {
    int i;
    int b;

    printf("ID    Name                            Books on loan\n");
    printf("------------------------------------------------------\n");
    for(i = 0; i < blist->numBorrowers; i++) {
        printf("%-4d  %-30s  %d",
            blist->borrowers[i]->id,
            blist->borrowers[i]->name,
            blist->borrowers[i]->numBooksBorrowed);

        if(blist->borrowers[i]->numBooksBorrowed > 0) {
            printf(" (%d", blist->borrowers[i]->booksBorrowed[0]->isbn);
            for(b = 1; b < blist->borrowers[i]->numBooksBorrowed; b++) {
                printf(", %d", blist->borrowers[i]->booksBorrowed[b]->isbn);
            }
            printf(")");
        }
        printf("\n");
    }
    printf("------------------------------------------------------\n");
}
