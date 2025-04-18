#include <ncursesw/ncurses.h>

#define PINK 1

int main (void)
{
    initscr();

    if (!has_colors())
    {
        endwin();
        fprintf(stderr, "Terminal cannot do colors!\n");
        return 1;
    }
    if (start_color() != OK)
    {
        endwin();
        fprintf(stderr, "Unable to start colors!\n");
        return 1;
    }

    // Alguns terminais podem fornecer uma funcionalidade de palete de cores
    // e, nesse caso, podemos definir nossas próprias cores com o Ncurses. Para
    // fazer isso precisamos descobrir se temos a funcionalidade e criar a cor:
    //
    //     can_change_color(): predicado que retorna TRUE se o terminal tiver a
    //                         funcionalidade de paleta de cores;
    //
    //     init_color(n, red, green, blue): define uma nova cor no padrão RGB.
    //
    // Depois que a nova cor foi criada, é possível utilizá-la para, por
    // exemplo, criar um novo color pair.
    if (!can_change_color())
        addstr("This probably won't work...\n");
    init_color(PINK, 1000, 750, 750);
    init_pair(1, PINK, COLOR_BLACK);

    attrset(COLOR_PAIR(1));
    printw("This is the new color %d.\n", PINK);

    refresh();
    getch();
    
    endwin();
    return 0;
}
