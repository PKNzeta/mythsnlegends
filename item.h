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

    ///* armor attributes */
    //int               a_armor;
    //ITEM_ARMOR_TYPE*  armor;

    ///* weapon attributes */
    //int               w_damage;
    //int               w_ch_to_hit;
    //ITEM_WEAPON_TYPE* weapon;

    ///* tool attributes */
    //ITEM_TOOL_TYPE*   tool;

    ///* potion attributes */
    //ITEM_POTION_TYPE* potion;
    //int               p_concentration;
    //int               p_fullness;

    ///* scroll */
    //ITEM_SCROLL_TYPE* scroll;

    ///* book attributes */
    //ITEM_BOOK_TYPE*   book;

    ///* wand attributes */
    //ITEM_WAND_TYPE*   wand;

    ///* food attributes */
    //ITEM_FOOD_TYPE*   food;

    ///* ring attributes */
    //ITEM_RING_TYPE*   ring;

    ///* gauntlet attibutes */
    //ITEM_GAUNTLET_TYPE* gauntlet;

    ///* other random attributes */
    //ITEM_OTHER_ATTRIBUTES* other */

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
