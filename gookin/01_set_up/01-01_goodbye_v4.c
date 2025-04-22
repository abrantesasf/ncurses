/**
 * Este programa compila perfeitamente e mostra a linha de texto na tela.
 */

#include <ncursesw/ncurses.h>

int main (void)
{
    // Inicializa a tela:
    initscr();

    // Imprime uma linha de texto na tela:
    addstr("Goodbye, cruel world!");

    // Faz o refresh da tela para exibir as atualizações:
    refresh();

    // Aguarda o input do usuário, exibindo a tela:
    getch();

    // Termina a sessão Ncurses:
    endwin();

    return 0;
}
