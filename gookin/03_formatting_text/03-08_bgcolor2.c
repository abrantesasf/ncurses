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

    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    init_pair(2, COLOR_GREEN, COLOR_WHITE);
    init_pair(3, COLOR_RED, COLOR_GREEN);
    
    // A função bkgd pode ser aplicada a qualquer momento, afetando qualquer
    // texto que já esteja na tela.
    bkgd(COLOR_PAIR(1));
    addstr("I think that I shall never see\n");
    addstr("a color screen as pretty as thee.\n");
    addstr("For seasons may change\n");
    addstr("and storms may thunder;\n");
    addstr("But color text shall always wonder.\n");

    refresh();
    getch();
    addstr("\b \b");
    
    bkgd(COLOR_PAIR(2));
    refresh();
    getch();
    addstr("\b \b");

    bkgd(COLOR_PAIR(3));
    refresh();
    getch();
    addstr("\b \b");

    endwin();
    return 0;
}
