#include <locale.h>
#include <ncursesw/ncurses.h>

int main (void)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    initscr();

    WINDOW *second = NULL;

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
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    init_pair(2, COLOR_WHITE, COLOR_RED);

    second = newwin(0, 0, 0, 0);
    if (!second)
    {
        endwin();
        fprintf(stderr, "Unable to create window\n");
        return 1;
    }
    wbkgd(second, COLOR_PAIR(2));
    waddstr(second, "This is the second window\n");

    bkgd(COLOR_PAIR(1));
    addstr("This is the standard screen\n");
    addstr("Press ENTER");
    refresh();
    getch();

    wrefresh(second);
    getch();

    // Para fazer a stdscr ser exibida novamente temos que usar a função
    // "touchwin" para forçar um update. A função "touchwin" faz com que o
    // Ncurses acredite que cada caractere em uma janela foi atualizado (ou
    // "tocado") desde o último refresh. Isso força um refresh total.
    touchwin(stdscr);
    refresh();
    getch();
    
    endwin();
    return 0;
}
