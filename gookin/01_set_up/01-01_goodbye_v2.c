/**
 * Este programa compila perfeitamente mas, ao ser executado, não exibe a linha
 * de texto na tela. Precisa ser corrigido em versão futura.
 */

#include <ncursesw/ncurses.h>

int main (void)
{
    // Inicializa a tela:
    initscr();

    // Imprime uma linha de texto na tela:
    addstr("Goodbye, cruel world!");

    // Termina a sessão Ncurses:
    endwin();

    return 0;
}
