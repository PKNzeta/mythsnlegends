#ifndef H__MENUS
#define H__MENUS

#define N_MENU_MAX 32

/* n  is the number of item in the menu */
#define MENU_POSITION_CENTER(n)\
    n,\
    (GFX_WIN_X_SIZE / 2) - (15 * GFX_TEXT_SIZE),\
    (GFX_WIN_Y_SIZE / 2) - (GFX_TEXT_SIZE * n) / 2

#define MENU_SEPARATOR\
    {"\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4"\
     "\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4", menu_separator}


/* This is a menu entry */
typedef struct menu_pair
{
    const char txt[31];
    void (*func) (void);
} MENU_PAIR;


/* and the menu itself */
typedef struct menu_struct
{
    MENU_PAIR  menu[N_MENU_MAX];

    /* Number of item in the menu */
    char       i;

    /* upper left corner of the menu */
    int x; int y;

} MENU;


MENU main_menu;

void menu_separator (void);
void menu_get_string (char* str, int len, int x, int y);
int menu_show (MENU* menu);

#endif /* H__MENUS */
