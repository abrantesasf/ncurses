#include <ncursesw/ncurses.h>
#include <string.h>

int main (void)
{
    initscr();

    char text[] = "Armstrong walks on moon!";
    char *t = text;
    int len = strlen(text);

    move(5, 1);
    for (char a = 'A'; a <= 'Z'; a++)
    {
        addch(a);
        addstr("  ");
    }
    refresh();
    
    while (len)
    {
        move(5, 0);               // insere no mesmo lugar
        insch(*(t + len - 1));    // de trás para frente
        refresh();
        napms(300);
        len--;
    }

    getch();

    endwin();
    return 0;
}
