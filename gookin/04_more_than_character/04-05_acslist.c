#include <ncursesw/ncurses.h>

int main (void)
{
    initscr();

    // O seguinte programa mostra a lista de ACS que está disponível em seu
    // terminal. Se um ACS não estiver disponível será exibido um caractere
    // normal alternativo.
    for (int a = 0; a < 127; a++)
    {
        printw("\t%2X:", a);
        addch(A_ALTCHARSET | a);
    }
    
    refresh();
    getch();

    endwin();
    return 0;
}
