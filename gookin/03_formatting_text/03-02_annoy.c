#include <ncursesw/ncurses.h>

#define COUNT 5

int main (void)
{
    char text[COUNT][10] =
        {
            "Do", "you", "find", "this", "silly?"
        };

    initscr();

    // Como cada atributo do texto é representado por um padrão único de bits,
    // podemos especificar mais de um atributo através de um bitwise OR:
    for (size_t a = 0; a < COUNT; a++)
    {
        for (size_t b = 0; b < COUNT; b++)
        {
            if (a == b) attrset(A_BOLD | A_UNDERLINE);
            printw("%s", text[b]);
            if (a == b) attroff(A_BOLD | A_UNDERLINE);
            addch(' ');
        }
        addstr("\b\n");
    }

    refresh();
    getch();

    endwin();
    return 0;
}
