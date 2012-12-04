#ifndef H__CHAR_SPELLS
#define H__CHAR_SPELLS

#include "char.h"

#define X(enum,func) enum,

enum
{
    #include "spells.def"
    N_CHAR_SPELL
};

typedef struct char_magic_slots
{
    int slots[N_CHAR_SPELL];
    void (*slots_cb[N_CHAR_SPELL]) (void*);
    int num_slot;
    int mp_max;

} CHAR_SPELL_SLOTS;

#endif /* H__CHAR_SPELLS */
