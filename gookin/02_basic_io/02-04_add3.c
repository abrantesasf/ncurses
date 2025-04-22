#include <ncursesw/ncurses.h>

int main (void)
{
    char t1[] = "Shall I compare thee";
    char t2[] = " to a summer's day?";
    
    initscr();

    addstr(t1);
    addstr(t2);

    // move(y, x) reposiciona o cursor em qualquer ponto da tela, a qualquer
    // momento (zero-based). As coordenadas são (cuidado para não confundir com
    // coordenadas cartesianas):
    //     y = linha (vertical)
    //     x = coluna (horizontal)
    move(2, 0);    // linha 3, coluna 1

    addstr("Though art more lovely...");

    refresh();
    getch();

    endwin();
    return 0;
}
