#include <locale.h>
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>


int main (void)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    initscr();

    addstr("Press Enter to restore the screen");
    refresh();
    getch();

    int r = scr_restore("dump.win");
    if( r == ERR)
        addstr("Error reading window file");
    refresh();
    getch();

    endwin();
    return(0);
}
