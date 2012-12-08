#ifndef H__CHAR
#define H__CHAR

#include "item.h"
#include "map_block.h"
#include "char_skills.h"
#include "char_spells.h"

typedef struct char_position
{
    /* x and y position on the block */
    int x;
    int y;

    /* this position is relative to this block */
    MAP_BLOCK* block;

} CHAR_POSITION;

typedef struct charac_struct
{
    char              name[16];
    CHAR_SKILL_SLOTS  skill;
    CHAR_SPELL_SLOTS magic;
    CHAR_POSITION     pos;
    ITEM_INV          inv;

    /* character current hp and mp */
    int hp; int mp;

    /* experience and level */
    int xp; int lvl;

    /* pass your turn if it is set to one */
    int           pass;

} CHARACTER;

#include "char_hero.h"

#endif /* H__CHAR */
