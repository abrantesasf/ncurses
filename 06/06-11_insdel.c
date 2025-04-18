#include <ncursesw/ncurses.h>

int main (void)
{
    initscr();

    // Ncurses tem uma função que faz a inserção e/ou a remoção de linhas
    // dependendo do argumento passado:
    //
    //     insdelln(n): se N é 0, nada ocorre;
    //                  se N > 0, são inseridas N linhas a partir da atual
    //                  se N < 0, são removidas N linhas a partir da atual
    //
    // A posição do cursor não se altera!
    for (int row = 0; row < LINES; row++)
        for (int col = 0; col < COLS; col++)
            addch('.');
    
    refresh();
    getch();

    move(5, 0);
    insdelln(3);
    refresh();
    getch();

    insdelln(-5);
    refresh();
    getch();

    endwin();
    return 0;
}
