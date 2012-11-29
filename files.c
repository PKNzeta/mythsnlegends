/** files.c
 * TODO: - files_closeall ()
 *         implement a opened file list so we can free them all
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Private definitions ********************************************************/

typedef struct spath_struct
{
    const char* str;
    struct spath_struct* nxt;
} SPATH;

#ifdef WIN32
#  define N_BASEDIR 1
#  define PTH_SEP "\\"
#else
#  define N_BASEDIR 4
#  define PTH_SEP "/"
#endif

/* Private data ***************************************************************/

#ifdef WIN32
static const char* base_dir[N_BASEDIR] =
{
    ".\\"
};
#else
static const char* base_dir[N_BASEDIR] =
{
    "./",
    "/usr/share/" PROGRAM_NAME "/",
    "/usr/local/share/" PROGRAM_NAME "/",
    "~/.share/" PROGRAM_NAME "/"
};
#endif


/* A buffer to where format paths */
static char pth_buf[128] = {'\0'};

/* a chained list of all the search paths */
static SPATH* paths = NULL;

/* Public functions ***********************************************************/

/* files_add_search_path ()
 * Add a the search path "pth". the path is relative to installation directory.
 * for exemple let's say that your program has a directory named data. the full
 * path will be; "/usr/share/program_name/data. then you must call this function
 * like this: files_add_search_path("data");
 * now, files will be searched in this directory
 */
void files_add_search_path (const char* pth)
{
    SPATH* newpth = malloc (sizeof (SPATH));
    newpth->nxt = paths;
    newpth->str = pth;
    paths = newpth;
}


/* files_open ()
 * try to find and open the given file "filename" into the different given
 * search paths
 * filename: the file name without path.
 * return: a FILE* pointing to the opened file or NULL on fail.
 */
FILE* files_open (const char* filename)
{
    FILE*  file = NULL;
    SPATH* cur = NULL;
    int i = 0;

    while (i < N_BASEDIR && file == NULL)
    {
        cur = paths;

        while (cur != NULL && file == NULL)
        {
            snprintf (pth_buf, 127, "%s%s" PTH_SEP "%s",
                      base_dir[i], cur->str, filename);
            file = fopen (pth_buf, "r");
            cur = cur->nxt;
        }
        i++;
    }

    return file;
}


/* files_locate ()
 * Try to find if the given file "filename" is present in the search paths.
 * filename: the filename we are looking for.
 * return: a constant string of the full path of filename or NULL if none found.
 *         take care of copying the result and not just point to it as it's
 *         subject to changes.
 */
const char* files_locate (const char* filename)
{
    FILE*  file = files_open (filename);

    if (file != NULL)
    {
        fclose (file);
    }

    return (file != NULL)? pth_buf : NULL;
}
