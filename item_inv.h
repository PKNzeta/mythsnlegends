#ifndef H__ITEM_INV
#define H__ITEM_INV

#define ITEM_INV_MAX 64

enum
{
    EQ_SLOT_HEAD,
    EQ_SLOT_NECK,
    EQ_SLOT_WEAPON,
    EQ_SLOT_SHIELD,
    EQ_SLOT_L_HAND,
    EQ_SLOT_R_HAND,
    EQ_SLOT_BOOTS,
    N_EQ_SLOT
};

typedef struct item_inv
{
    ITEM*   item[ITEM_INV_MAX];
    ITEM*   equiped[N_EQ_SLOT];
} ITEM_INV;

/* Add the item itm at the first free slot of the inventory inv
 * return 1 on success 0 on failure */
int item_inventory_add (ITEM_INV* inv, ITEM* itm);

/* Sort inventory with item types */
void item_inventory_sort (ITEM_INV* inv);

/* print the inventory */
void dbg_print_inventory (ITEM_INV* inv);

#endif /* H__ITEM_INV */
