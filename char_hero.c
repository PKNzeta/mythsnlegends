#include <stdlib.h>
#include <stdio.h>
#include "char.h"

CHARACTER Hero =
{
    /* Character name */
    "Arthur",

    /* Initial character skills */
    {
        {0},  /* skill slots */
        1,    /* Max number of learned skills */
        15    /* Maximum HP */
    },

    /* Initial character magic attributes */
    {
        {0},  /* spell slots */
        1,    /* Max number of learned spells */
        10    /* Max MP */
    },

    /* the character position */
    {
        0, 0,
        NULL
    },

    /* initial inventory */
    {{NULL}, {NULL}},

    /* Hit points and magic points */
    15, 10,

    /* XP, and level */
    0, 1,

    /* Pass your turn? */
    0,

    /* Number of turn since the player had spawn */
    0
};
