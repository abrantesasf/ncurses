#include <locale.h>
#include <ncurses.h>

int main (void)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    initscr();

    MEVENT mort;
    int ch;

    noecho();
    keypad(stdscr, TRUE);

    mousemask(ALL_MOUSE_EVENTS, NULL);

    while (1)
    {
        ch = getch();
        if (ch == KEY_MOUSE)
        {
            getmouse(&mort);
            move(mort.y, mort.x);
            printw("*");
            refresh();
            continue;
        }
        if (ch == '\n')
            break;
    }

    endwin();
    return 0;
}
