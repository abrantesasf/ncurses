#include <locale.h>
#include <ncursesw/ncurses.h>

int main (void)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    initscr();

    // Ao se trabalhar com múltiplas janelas é necessário ter uma maneira de
    // exibir cada uma delas a um determinado momento. A função wrefresh() é
    // usada para isso.
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
    
    endwin();
    return 0;
}
