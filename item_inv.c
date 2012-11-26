#include <stdlib.h>
#include "item.h"

/** Private functions
 **************************************************************************/

 static int item_inventory_sort__compare
    (const void* a, const void* b)
{
    ITEM* itm1 = (ITEM*) a;
    ITEM* itm2 = (ITEM*) b;

    return (itm1->type > itm2->type)? 0 : 1;
}

/** Public functions
 **************************************************************************/


int item_inventory_add (ITEM_INV* inv, ITEM* itm)
{
    int i = 0;

    while (i < ITEM_INV_MAX)
    {
        if (inv->item[i] == NULL)
        {
            inv->item[i] = itm;
            i = 999;
        }
    }

    return (i == 999)? 1 : 0;
}


void item_inventory_sort (ITEM_INV* inv)
{
    qsort ((void*) inv, ITEM_INV_MAX, sizeof (ITEM*), item_inventory_sort__compare);
}
