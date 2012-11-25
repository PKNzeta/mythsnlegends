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
    GAUNTLET
} ITEM_TYPE;

typedef struct item_struct
{
    const char* name;
    ITEM_TYPE   type;

    /* General attributes */
    int               hp;
    int               cursed;

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

} ITEM;

#include "item_inv.h"

#endif /* H__ITEM */
