#ifndef H__HERO
#define H__HERO

#include "item.h"
#include "char_skills.h"
#include "char_magics.h"
#include "char_hero.h"
#include "map_block.h"

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
    char             name[16];
    CHAR_SKILL_SLOTS skill;
    CHAR_MAGIC_SLOTS magic;
    CHAR_POSITION    pos;
    ITEM_INV         inv;

    /* character current hp and mp */
    int hp; int mp;

    /* experience and level */
    int xp; int lvl;

    /* pass your turn if it is set to one */
    int           pass;

    /* number of turn that the hero played */
    long          turn;

} CHARACTER;

CHARACTER Hero;

#endif /* H__HERO */
