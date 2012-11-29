#ifndef H__CHAR_SKILLS
#define H__CHAR_SKILLS

#include "char.h"

typedef enum
{
    N_CHAR_SKILL
} CHAR_SKILL;

typedef struct char_skill_slots
{
    CHAR_SKILL slots[32];
    int num_slot;
    int hp_max;

} CHAR_SKILL_SLOTS;

#endif /* H__CHAR_SKILLS */
