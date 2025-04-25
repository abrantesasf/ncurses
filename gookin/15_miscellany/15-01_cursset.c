#include <locale.h>
#include <ncurses.h>

int main (void)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    initscr();

    // Alguns terminais suprotam que você desabilite o cursor, escondendo-o
    // temporariamente, ou coloque o cursor em um modo "mais visível". A função
    // para isso é a curs_set:
    //
    //     curs_set(n)
    //        se n = 0: desliga o cursor
    //        se n = 1: liga o cursor normal
    //        se n = 2: liga o cursor destacado
    //
    // Se o terminal não suportar essa funcionalidade, a função retorna ERR e
    // nada de especial acontece.
    curs_set(0);
    addstr("  <- The cursor has been turned off");
    move(0,0);
    refresh();
    getch();

    curs_set(1);
    addstr("\n  <- The cursor now on");
    move(1,0);
    refresh();
    getch();

    curs_set(2);
    addstr("\n  <- The cursor is now very on");
    move(2,0);
    refresh();
    getch();

    endwin();
    return 0;
}
