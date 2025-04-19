#include <ncursesw/ncurses.h>

int main (void)
{
    initscr();

    // A função getch(), por padrão, exibe o caractere que foi digitado na tela.
    // Podemos habilitar ou não esse comportamento com as funções:
    //     echo()
    //     noecho()
    // Essas funções só afetam a exibição do caractere, não alteram o bloqueio
    // e getch() continua fazendo refresh() automático.

    int key1, key2;

    addstr("Type a key: ");
    refresh();
    key1 = getch();
    napms(1000);                         // Só para exibir a letra por 1s
    clear();

    addstr("Type the same key: ");
    noecho();
    key2 = getch();

    move(1, 0);
    if (key1 == key2)
        addstr("The keys match");
    else
        addstr("The keys don't match");

    refresh();
    getch();

    endwin();
    return 0;
}
