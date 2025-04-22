#include <locale.h>
#include <ncurses.h>

int main (void)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");

    // A função scroll(win) faz uma rolagem manual da tela por 1 linha, se a
    // rolagem estiver ativada. A linha superior é perdida após a rolagem. A
    // função scroll(win) NÃO ALTERA a posição do cursor.
    initscr();

    scrollok(stdscr, TRUE);
    
    for (int x = 0; x < LINES; x++)
        mvprintw(x, 0, "%2d", x);

    refresh();
    getch();

    scroll(stdscr);
    refresh();
    getch();

    endwin();
    return 0;
}
