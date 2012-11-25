#ifndef H__HERO
#define H__HERO

#include "item.h"
#include "char_stat.h"
#include "map_block.h"

typedef struct char_position
{
    /* x and y position on the block */
    int x;
    int y;

    /* this position is relative to this block */
    MAP_BLOCK* block;

} CHAR_POSITION;

typedef struct hero
{
    char          name[16];
    CHAR_STAT     stat;
    CHAR_POSITION pos;
    ITEM_INV*     inv;

    /* pass your turn if it is set to one */
    int           pass;

    /* number of turn that the hero played */
    long          turn;

} HERO;

HERO Hero;

//void dbg_print_hero_stat (void);

#endif /* H__HERO */
