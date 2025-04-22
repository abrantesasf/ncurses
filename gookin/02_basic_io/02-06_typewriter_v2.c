#include <ncursesw/ncurses.h>

int main (void)
{
    int ch;

    initscr();

    addstr("Type a few lines of text.\n");
    addstr("Press ESC to quit.\n");
    
    refresh();

    // Para evitar o problema de '~' ser uma "dead-key" em teclados ABNT/ABNT2,
    // vamos usar a tecla ESC para terminar o programa (inteiro 27 em ASCII).
    while ((ch = getch()) != 27)
        ;

    endwin();
    return 0;
}
