#include <locale.h>
#include <ncursesw/ncurses.h>

int main (void)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
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
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    init_pair(2, COLOR_WHITE, COLOR_RED);
    init_pair(3, COLOR_WHITE, COLOR_GREEN);
    init_pair(4, COLOR_WHITE, COLOR_CYAN);

    WINDOW *jan1 = NULL;
    WINDOW *jan2 = NULL;
    WINDOW *jan3 = NULL;
    WINDOW *jan4 = NULL;

    attrset(A_BOLD);

    jan1 = newwin(LINES/2, COLS/2, 0, 0);
    if (!jan1)
    {
        endwin();
        fprintf(stderr, "Unable to create first window\n");
        return 1;
    }
    wbkgd(jan1, COLOR_PAIR(1));
    wattrset(jan1, A_BOLD);
    wborder(jan1, 0, 0, 0, 0, 0, 0, 0, 0);
    wmove(jan1, 1, 1);
    waddstr(jan1, "This is the first window");
    wmove(jan1, 2, 1);

    jan2 = newwin(LINES/2, COLS/2, 0, COLS/2);
    if (!jan2)
    {
        endwin();
        fprintf(stderr, "Unable to create second window\n");
        return 1;
    }
    wbkgd(jan2, COLOR_PAIR(2));
    wattrset(jan2, A_BOLD);
    wborder(jan2, 0, 0, 0, 0, 0, 0, 0, 0);
    wmove(jan2, 1, 1);
    waddstr(jan2, "This is the second window");
    wmove(jan2, 2, 1);

    jan3 = newwin(LINES/2, COLS/2, LINES/2, 0);
    if (!jan3)
    {
        endwin();
        fprintf(stderr, "Unable to create third window\n");
        return 1;
    }
    wbkgd(jan3, COLOR_PAIR(3));
    wattrset(jan3, A_BOLD);
    wborder(jan3, 0, 0, 0, 0, 0, 0, 0, 0);
    wmove(jan3, 1, 1);
    waddstr(jan3, "This is the third window");
    wmove(jan3, 2, 1);

    jan4 = newwin(LINES/2, COLS/2, LINES/2, COLS/2);
    if (!jan4)
    {
        endwin();
        fprintf(stderr, "Unable to create fourth window\n");
        return 1;
    }
    wbkgd(jan4, COLOR_PAIR(4));
    wattrset(jan4, A_BOLD);
    wborder(jan4, 0, 0, 0, 0, 0, 0, 0, 0);
    wmove(jan4, 1, 1);
    waddstr(jan4, "This is the fourth window");
    wmove(jan4, 2, 1);

    addstr("This is the standard screen\n");
    addstr("Press ENTER");
    refresh();
    getch();

    wrefresh(jan1);
    getch();

    wrefresh(jan2);
    getch();

    wrefresh(jan3);
    getch();

    wrefresh(jan4);
    getch();

    touchwin(stdscr);
    refresh();
    getch();
    
    endwin();
    return 0;
}
