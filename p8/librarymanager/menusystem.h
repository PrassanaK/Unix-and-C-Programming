#ifndef MENUSYSTEM_H
#define MENUSYSTEM_H

#include "catalogue.h"
#include "borrowerlist.h"

/* Executes the library manager's menu system, given a catalogue and borrower
   list. */
void menuSystem(Catalogue* cat, BorrowerList* bor);

#endif