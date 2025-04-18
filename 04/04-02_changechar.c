#include <ncursesw/ncurses.h>

int main (void)
{
    initscr();

    // Quando um caractere chtype é usado com uma função de output do Ncurses,
    // qualquer atributo previamente aplicado a uma posição de um caractere é
    // sobrescrito.
    addch('c');
    addch('a' | A_BOLD);
    addch('t' | A_REVERSE);
    refresh();
    getch();

    move(0, 2);
    addch('r');
    refresh();
    getch();

    endwin();
    return 0;
}
