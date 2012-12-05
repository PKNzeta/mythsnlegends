#ifndef H__MENUS
#define H__MENUS

#define N_MENU_MAX 32


/* This is a menu entry */
typedef struct menu_pair
{
    const char txt[33];
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


int menu_show_menu (MENU* menu);

#endif /* H__MENUS */
