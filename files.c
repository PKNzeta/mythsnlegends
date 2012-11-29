#include <stdlib.h>
#include <stdio.h>

#ifdef WIN32

#define N_BASEDIR 1
#define PTH_SEP "\\"

static const char* base_dir[N_BASEDIR] =
{
    "./"
};

#else

#define N_BASEDIR 4
#define PTH_SEP "/"
static const char* base_dir[N_BASEDIR] =
{
    "./",
    "/usr/share/" PROGRAM_NAME "/",
    "/usr/local/share/" PROGRAM_NAME "/",
    "~/.share/" PROGRAM_NAME "/"
};

#endif


typedef struct spath_struct
{
    const char* str;
    struct spath_struct* nxt;
} SPATH;


SPATH* paths = NULL;


void files_add_search_path (const char* pth)
{
    SPATH* newpth = malloc (sizeof (SPATH));
    newpth->nxt = paths;
    newpth->str = pth;
    paths = newpth;
}

FILE* files_open (const char* filename)
{
    FILE*  file = NULL;
    SPATH* cur = paths;
    int    i = 0;

    while (cur != NULL && file == NULL)
    {
        char   pth_buf[128] = {'\0'};

        snprintf (pth_buf, 127, "%s%s" PTH_SEP "%s",
                  base_dir[i], cur->str, filename);
        file = fopen (pth_buf, "r");

        cur = cur->nxt; i++;
    }

    return file;
}
