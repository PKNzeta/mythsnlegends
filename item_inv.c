
#include <stdlib.h>
#include "item.h"

/* Add the item itm at the end of inventory inv
 * return the the newly created inventory slot address */
ITEM_INV* item_add_to_inventory (ITEM_INV* inv, ITEM* itm)
{
    if (inv == NULL)
    {
        inv = malloc (sizeof (ITEM_INV));
        inv->item = itm;
        inv->nxt = inv->prv = NULL;
    }
    else
    {
        /* go to the end of the inventory */
        while (inv->nxt != NULL) inv = inv->nxt;
        inv->nxt = malloc (sizeof (ITEM_INV));
        inv->nxt->item = itm;
        inv->nxt->nxt = inv->nxt->prv = NULL;
        inv = inv->nxt;
    }

    return inv;
}
