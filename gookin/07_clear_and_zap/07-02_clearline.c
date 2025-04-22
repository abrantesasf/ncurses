#include <ncursesw/ncurses.h>

int main (void)
{
    initscr();

    // Quando é necessário limpar apenas parte da tela, temos duas funções que
    // podem ser muito úteis:
    //
    //     clrtoeol()  = limpa da posição atual do cursor até o final da linha
    //     clrtobot()  = limpa da posição atual do cursor até o final da tela
    //
    // Nenhuma das duas funções altera a posição atual do cursor!
    int y, x;
    getmaxyx(stdscr, y, x);

    int cmax = (y * x) / 5;

    for (int c = 0; c < cmax; c++)
        addstr("blah ");
    refresh();
    getch();

    move(5, 20);
    clrtoeol();

    refresh();
    getch();

    endwin();
    return 0;
}
