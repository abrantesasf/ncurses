#include <locale.h>
#include <ncursesw/ncurses.h>

int main (void)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    initscr();

    WINDOW *tiny = NULL;

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

    // A maior janela que pode ser criada é do tamanho da stdscr e a menor do
    // tamanho de 1 caractere. Aqui criamos uma janela menor:
    tiny = newwin(LINES/2, COLS/2, LINES/4, COLS/4);
    if (!tiny)
    {
        endwin();
        fprintf(stderr, "Unable to create window\n");
        return 1;
    }
    wbkgd(tiny, COLOR_PAIR(2));
    waddstr(tiny, "This is the tiny window\n");

    bkgd(COLOR_PAIR(1));
    addstr("This is the standard screen\n");
    addstr("Press ENTER");
    refresh();
    getch();

    wrefresh(tiny);
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
