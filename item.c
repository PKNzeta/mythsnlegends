#include "item.h"
#include "stdio.h"

/** Private data
 ******************************************************************************/

 static char item_name_str[128] = {'\0'};


/** Public functions
 ******************************************************************************/

const char* item_print_name (ITEM* itm)
{
    if (itm->identified)
    {
        if (itm->cursed == 0)
        {
            sprintf (item_name_str, "a %s", itm->name);
        }
        else if (itm->cursed == 1)
        {
            sprintf (item_name_str, "a cursed %s", itm->name);
        }
        else
        {
            sprintf (item_name_str, "a holy %s", itm->name);
        }
    }
    else
    {
        sprintf (item_name_str, "an unidentified %s", itm->name);
    }

    return item_name_str;
}

