#ifndef H__CHAR_SKILLS
#define H__CHAR_SKILLS

#include "char.h"

enum
{
    CHAR_SKILL_SMALL_WEAPON,
    CHAR_SKILL_MEDIUM_WEAPON,
    CHAR_SKILL_LARGE_WEAPON,
    N_CHAR_SKILL
};

typedef struct
{
    int slots[N_CHAR_SKILL];
    void (*slots_cb[N_CHAR_SKILL]) (void*);
    int num_slot;
    int hp_max;

} CHAR_SKILL_SLOTS;

#endif /* H__CHAR_SKILLS */
