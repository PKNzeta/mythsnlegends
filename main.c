
#include <stdlib.h>
#include <stdio.h>
#include "gfx.h"
#include "toolkit_monster_edit.h"

int main (int argc, char** argv)
{
    atexit (gfx_free);
    gfx_init ();
    monster_editor ();

    return EXIT_SUCCESS;
}
