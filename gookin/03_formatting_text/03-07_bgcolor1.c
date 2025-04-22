#include <ncursesw/ncurses.h>

int main (void)
{
    initscr();

    if (!has_colors())
    {
        endwin();
        fprintf(stderr, "Terminal cannot do colors.\n");
        return 1;
    }
    if (start_color() != OK)
    {
        endwin();
        fprintf(stderr, "Unable to start colors.\n");
        return 1;
    }

    // As cores no Ncurses podem ser atributos do texto e também atributos das
    // telas ou janelas. Para isto usamos:
    //
    //     bkgd(attrs): esta função é semelhante à attrset(attrs) para o texto.
    //                  Aqui podemos criar um color pair e atribuir esse color
    //                  pair para o stdscr.
    //
    // Todo texto exibido herda a cor de background da screen, mas podemos
    // ajustar o texto com attrset, attron ou attroff.
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    bkgd(COLOR_PAIR(1));

    attron(A_BOLD);
    addstr("This is some text.\n");

    refresh();
    getch();

    endwin();
    return 0;
}
