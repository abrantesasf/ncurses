/**
 * Este programa contém, de propósito, um erro no argumento da função "addstr"
 * e, portanto, não irá compilar corretamente. Esse erro será corrigido nas
 * próximas versões.
 */

#include <ncursesw/ncurses.h>

int main (void)
{
    // Inicializa a tela:
    initscr();

    // Imprime uma linha de texto na tela:
    addstr(Goodbye, cruel world!);

    // Termina a sessão Ncurses:
    endwin();

    return 0;
}
