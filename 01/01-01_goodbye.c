#include <ncurses.h>

int main (void)
{
    initscr();
    addstr("Goodbye, cruel world!");
    refresh();
    getch();

    endwin();
    return 0;
}
