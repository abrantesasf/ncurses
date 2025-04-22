#include <ncursesw/ncurses.h>

int main (void)
{
    initscr();

    // A qualquer momento você pode descobrir a posição exata do cursor com
    // a macro "getyx(win, y, x)".
    addstr("Type some text; '~' to end:\n");
    refresh();

    int row, col;
    char ch;

    while ((ch = getch()) != '~')
        ;

    getyx(stdscr, row, col);
    addch('X');

    printw("\n\nThe cursor was at position (%d, %d) ", row, col);
    printw("when you stopped typing (the big 'X').");
    
    refresh();
    getch();

    endwin();
    return 0;
}
