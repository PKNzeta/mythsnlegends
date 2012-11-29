#ifndef H__FILES
#define H__FILES

void files_add_search_path (const char* pth);

FILE* files_open (const char* filename);

const char* files_locate (const char* filename);

#endif
