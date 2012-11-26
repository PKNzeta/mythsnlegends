#ifndef H__ITEM_INV
#define H__ITEM_INV

#define ITEM_INV_MAX 64

typedef struct item_inv
{
    ITEM*   item[ITEM_INV_MAX];
} ITEM_INV;

/* Add the item itm at the first free slot of the inventory inv
 * return 1 on success 0 on failure */
int item_inventory_add (ITEM_INV* inv, ITEM* itm);

/* Sort inventory with item types */
void item_inventory_sort (ITEM_INV* inv);

#endif /* H__ITEM_INV */
