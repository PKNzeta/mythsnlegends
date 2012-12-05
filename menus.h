#ifndef H__MENUS
#define H__MENUS

#define N_MENU_MAX 32

typedef struct menu_pair
{
    const char txt[32];
    void (*func) (void);
} MENU_PAIR;

typedef struct menu_struct
{
    MENU_PAIR  menu[N_MENU_MAX];
    char       i;
} MENU;

MENU main_menu;

int menu_show_menu (MENU* menu);

#endif /* H__MENUS */
