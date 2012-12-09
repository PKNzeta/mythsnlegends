#ifndef H__FILES
#define H__FILES

#ifdef WIN32
#  define N_BASEDIR 1
#  define PTH_SEP "\\"
#else
#  define N_BASEDIR 4
#  define PTH_SEP "/"
#endif

/* files_add_search_path ()
 * Add a the search path "pth". the path is relative to installation directory.
 * for exemple let's say that your program has a directory named data. the full
 * path will be; "/usr/share/program_name/data. then you must call this function
 * like this: files_add_search_path("data");
 * now, files will be searched in this directory
 */
void files_add_search_path (const char* pth);


/* files_open ()
 * try to find and open the given file "filename" into the different given
 * search paths
 * filename: the file name without path.
 * return: a FILE* pointing to the opened file or NULL on fail.
 */
FILE* files_open (const char* filename);


/* files_locate ()
 * Try to find if the given file "filename" is present in the search paths.
 * filename: the filename we are looking for.
 * return: a constant string of the full path of filename or NULL if none found.
 *         take care of copying the result and not just point to it as it's
 *         subject to changes.
 */
const char* files_locate (const char* filename);

#endif
