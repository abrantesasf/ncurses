/**
 * Este programa compila perfeitamente mas, ao ser executado, exibe a linha de
 * texto na tela, mas de forma tão rápida que não conseguimos ver. Precisa ser
 * corrigido em versão futura.
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

    // Termina a sessão Ncurses:
    endwin();

    return 0;
}
