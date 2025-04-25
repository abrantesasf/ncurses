#include <locale.h>
#include <ncurses.h>

#define HLIN 10
#define VLIN 5

int main (void)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    initscr();

    int y[] = {  0,  0, 5,  0,  5,  5, 10, 10, 10, 10, 15, 5 };
    int x[] = { 10, 10, 1, 20, 20, 30,  1, 10, 20, 20, 10, 0 };

    for(int c = 0; c < 12; c += 2)
    {   
        mvhline(   y[c],   x[c], 0, HLIN);
        mvvline( y[c + 1], x[c + 1], 0, VLIN);
    }

    mvaddch(0, 10, ACS_ULCORNER);
    mvaddch(0, 20, ACS_URCORNER);

    mvaddch(5, 0, ACS_ULCORNER);
    mvaddch(5, 10, ACS_LRCORNER);
    mvaddch(5, 20, ACS_LLCORNER);
    mvaddch(5, 30, ACS_URCORNER);

    mvaddch(10, 0, ACS_LLCORNER);
    mvaddch(10, 10, ACS_URCORNER);
    mvaddch(10, 20, ACS_ULCORNER);
    mvaddch(10, 30, ACS_LRCORNER);

    mvaddch(15, 10, ACS_LLCORNER);
    mvaddch(15, 20, ACS_LRCORNER);

    refresh();
    getch();

    endwin();
    return 0;
}
