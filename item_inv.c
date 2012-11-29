#include <stdlib.h>
#include <stdio.h>
#include "item.h"

/** private data
 **************************************************************************/


/** Private functions
 **************************************************************************/

 static int item_inventory_sort__compare
    (const void* a, const void* b)
{
    int ret = 0;
    ITEM* itm1 = (ITEM*) a;
    ITEM* itm2 = (ITEM*) b;

    if (itm2 == NULL)
    {
        ret = 1;
    }
    else if (itm1 == NULL)
    {
        ret = 0;
    }
    else if (itm1->type > itm2->type)
    {
        ret = 0;
    }
    else
    {
        ret = 1;
    }

    return ret;
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


void dbg_print_inventory (ITEM_INV* inv)
{
    int i = 0;
    int n = 0;

    fprintf (stderr,
     "\nInventory :\n"
     "===========\n");

    while (i < ITEM_INV_MAX)
    {
        if (inv->item[i] != NULL)
        {
            fprintf (stderr, "- %s\n", item_print_name (inv->item[i]));
            n++;
        }
        i++;
    }

    if (n == 0)
    {
        fprintf (stderr, "Empty\n");
    }
}
