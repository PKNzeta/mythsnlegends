/* history.h */

#ifndef H__HISTORY
#define H__HISTORY

typedef struct history_line_struct
{
    char   line[96];
    struct history_line_struct* nxt;
} MESSAGE;

MESSAGE* messages;

void messages_tell (const char* msg);
void messages_history (void);

#endif /* H__HISTORY */
