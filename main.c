
#include <stdlib.h>
#include "gfx.h"
#include "toolkit_monster_edit.h"

int main (int argc, char** argv)
{
    /* avoid compiler warnings */
    (void) argv; (void) argc;

    atexit (gfx_free);
    gfx_init ();
    monster_editor ();

    return EXIT_SUCCESS;
}
