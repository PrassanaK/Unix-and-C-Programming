/*
 * This is a simple Library Manager system, written for teaching purposes. It
 * has two deliberately seeded defects (and possibly other unknown ones!)
 *
 * Written by David Cooper (2010), Curtin University.
 */

#include "menusystem.h"
#include "catalogue.h"
#include "borrowerlist.h"

int main()
{
    Catalogue* cat = createCatalogue();
    BorrowerList* blist = createBorrowerList();

    menuSystem(cat, blist);

    freeCatalogue(cat);
    freeBorrowerList(blist);

    return 0;
}
