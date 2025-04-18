#include <ncursesw/ncurses.h>
#include <string.h>

int main (void)
{
    initscr();

    addstr("Where did that silly cat go?");

    refresh();
    getch();

    move(0, 15);
    for (int i = 0; i < 5; i++)
    {
        delch();
        refresh();
        napms(300);
    }

    char text[] = "fat fat fat";
    int len = strlen(text);

    for (int i = len - 1; i >= 0; i--)
    {
        insch(text[i]);
        refresh();
        napms(300);
    }

    getch();

    endwin();
    return 0;
}
