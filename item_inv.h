#ifndef H__ITEM_INV
#define H__ITEM_INV

typedef struct item_inv
{
    ITEM*  item;
    struct item_inv* nxt;
    struct item_inv* prv;
} ITEM_INV;

/* Add the item itm at the end of inventory inv
 * return the the newly created inventory slot address */
ITEM_INV* item_add_to_inventory (ITEM_INV* inv, ITEM* itm);

#endif /* H__ITEM_INV */
