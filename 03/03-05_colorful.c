#include <ncursesw/ncurses.h>

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

    // Apesar de Ncurses ajustar COLORS para a quantidade exata de cores
    // disponíveis no terminal, na verdade podemos utilizar o dobro da
    // quantidade informada em COLORS, aplicando como atributo, além da cor,
    // o A_BOLD. Isso faz com que o foreground seja mais "brilhoso",
    // efetivamente ilustrado como uma "nova" cor.
    init_pair(1, COLOR_BLACK, COLOR_RED);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);

    attrset(COLOR_PAIR(1));
    addstr("I am Mr. Black on Red!\n");

    attrset(COLOR_PAIR(2));
    addstr("I am Mr. Yellow on Black!\n");

    attrset(COLOR_PAIR(1) | A_BOLD);
    addstr("I'm feeling bold!\n");

    attrset(COLOR_PAIR(2) | A_BOLD);
    addstr("Me too!\n");

    refresh();
    getch();
    
    endwin();
    return 0;
}
