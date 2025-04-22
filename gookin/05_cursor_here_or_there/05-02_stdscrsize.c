#include <ncursesw/ncurses.h>

int main (void)
{
    initscr();

    // Além da macro "getmaxyx", também é possível utilizar duas constantes
    // globais populadas no momento da inicialização do Ncurses:
    //     LINES = número de linhas do terminal
    //     COLS  = número de colunas do terminal
    printw("Window is %d rows by %d columns.\n", LINES, COLS);
    
    refresh();
    getch();

    endwin();
    return 0;
}
