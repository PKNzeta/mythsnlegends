
#include <stdio.h>
#include "char_hero.h"

HERO Hero =
{
    /* Character name */
    "Arthur          ",

    /* initial character status */
    {
        /* HP & Max HP */
        15, 15,

        /* MP & Max MP */
        10, 10,

        /* Experience */
        0,

        /* Level */
        1,
    },

    /* the character position */
    {
        0, 0,
        NULL
    },

    /* initial inventory */
    NULL,

    /* Pass your turn? */
    0,

    /* Number of turn since the player had spawn */
    0
};

/*
void dbg_print_hero_stat (void)
{
    fprintf (stderr,
             "Hero name: %s\n"
             "HP: %d / %d\tMP: %d / %d\n"
             "XP: %d\tLevel: %d\n"
             "Inventory: {not implemented yet}\n"
             "Pass? %d\n"
             "Turn: %ld\n",
             Hero.name,
             Hero.stat.hp, Hero.stat.hp_max,
             Hero.stat.mp, Hero.stat.mp_max,
             Hero.stat.xp,
             Hero.stat.lvl,
             Hero.pass,
             Hero.turn);
}
*/
