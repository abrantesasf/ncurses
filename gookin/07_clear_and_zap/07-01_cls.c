#include <ncursesw/ncurses.h>

int main (void)
{
    initscr();

    // Quando é necessário limpar toda a tela, há 2 funções para isso:
    //
    //     erase()    = rápida, mas menos utilizada
    //     clear()    = mais overhead, mas é a preferida
    //
    int y, x;
    getmaxyx(stdscr, y, x);

    int cmax = (y * x) / 5;

    for (int i = 0; i < cmax; i++)
        addstr("blah ");
    
    refresh();
    getch();

    clear();

    refresh();
    getch();

    endwin();
    return 0;
}
