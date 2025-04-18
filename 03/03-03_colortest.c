#include <ncursesw/ncurses.h>

int main (void)
{
    initscr();

    // Para trabalhar com cores no terminal, temos o seguinte:
    //
    //     has_colors(): predicado que informa se o terminal suporta cores.
    //                   Retorna true ou false.
    //
    //     start_color(): inicializa as funcionalidades de cor. Se as cores
    //                    foram inicializadas, retorna OK e ajusta algumas
    //                    variáveis importantes:
    //                    - COLORS      = número de cores do terminal (0 a n-1)
    //                    - COLOR_PAIRS = número de pares de cores (1 a n)
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

    printw("Colors initialized.\n");
    printw("%d colors available.\n", COLORS);
    printw("%d colors pairs.", COLOR_PAIRS);

    refresh();
    getch();
    
    endwin();
    return 0;
}
