
#include <stdlib.h>
#include "gfx.h"
#include "files.h"

void main_quit (void)
{
    gfx_free ();
}

void main_init (void)
{
    atexit (main_quit);
    gfx_init ();
    files_add_search_path ("gfx");
}

int main (int argc, char** argv)
{
    /* avoid compiler warnings */
    (void) argv; (void) argc;

    main_init ();

    return EXIT_SUCCESS;
}
