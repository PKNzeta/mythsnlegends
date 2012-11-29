#ifndef H__CHAR_MAGICS
#define H__CHAR_MAGICS

#include "char.h"

typedef enum
{
    N_CHAR_MAGIC_SKILL
} CHAR_MAGIC_SKILL;

typedef struct char_magic_slots
{
    CHAR_MAGIC_SKILL slots[32];
    int num_slot;
    int mp_max;

} CHAR_MAGIC_SLOTS;

#endif /* H__CHAR_MAGICS */
