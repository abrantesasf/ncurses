#include <ncursesw/ncurses.h>

int main (void)
{
    initscr();

    // A posição do cursor é afetada por todas as funções de output em Ncurses.
    // Além disso é possível controlar exatamente a posição do cursor para
    // imprimir texto no local exato. Toda a movimentação do cursor tem como
    // base o canto superior esquerdo, considerado o ponto (y, x) = (0, 0),
    // sendo y o deslocamento vertical (a linha) e x o deslocamento horizontal
    // (a coluna). As principais funções são:
    //
    //     move(y, x)   = coloca o cursor em uma posição de y (linha) e x
    //                    (coluna) exata. As posição vão de 0 até N-1.
    //
    //     mvaddch(y, x, ch) = move o cursor para a posição e imprime um
    //                         caractere.
    //
    //     mvaddstr(y, x, *str) = move o cursor para a posição e imprime uma
    //                            string.
    //
    //     mvprintw(y, x, format, args) = move o cursor para a posição exata e
    //                                    imprime uma string de acordo com um
    //                                    especificador de formato.
    int lines, cols;
    getmaxyx(stdscr, lines, cols);
    lines--;
    cols--;

    attrset(A_BOLD | A_REVERSE);

    mvaddch(0, 0, '*');              // UL corner
    refresh();
    napms(2000);

    mvaddch(0, cols, '*');           // UR corner
    refresh();
    napms(2000);

    mvaddch(lines, 0, '*');          // LL corner
    refresh();
    napms(2000);

    mvaddch(lines, cols, '*');       // LR corner
    refresh();
    napms(2000);

    getch();

    endwin();
    return 0;
}
