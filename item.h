#ifndef H__ITEM
#define H__ITEM

typedef enum
{
    HELM,
    ARMOR,
    BOOTS,
    SHIELD,
    WEAPON,
    TOOL,
    POTION,
    SCROLL,
    BOOK,
    WAND,
    FOOD,
    RING,
    GAUNTLET,
    OTHER,
    ITEM_TYPE_NUM
} ITEM_TYPE;

typedef struct item_struct
{
    const char* name;
    ITEM_TYPE   type;

    /* General attributes */
    int         hp;
    int         cursed; /* 0:Normal 1:Cursed 2:Blessed */
    int         identified;

    /* Item attributes */
    /* it can be one of them:
        ITEM_ARMOR_TYPE*
        ITEM_WEAPON_TYPE*
        ITEM_TOOL_TYPE*
        ITEM_POTION_TYPE*
        ITEM_SCROLL_TYPE*
        ITEM_BOOK_TYPE*
        ITEM_WAND_TYPE*
        ITEM_FOOD_TYPE*
        ITEM_RING_TYPE*
        ITEM_GAUNTLET_TYPE*
        ITEM_OTHER_TYPE* */
    void*       attrib;

    /* Items can be stacked, this point to the previous
     * and the next item in the stack */
    struct item_struct* nxt;
    struct item_struct* prv;
} ITEM;

/* return a pointer the a string of the item name like "a holly truc bidule +1"
 */
const char* item_print_name (ITEM* itm);

#include "item_inv.h"

#endif /* H__ITEM */
