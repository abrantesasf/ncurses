#include <locale.h>
#include <ncursesw/ncurses.h>

int main (void)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    initscr();

    // Cria uma subwindow da stdscr:
    int rows = LINES / 2;
    int cols = COLS / 2;
    int y = (LINES - rows) / 2;
    int x = (COLS - cols) / 2;
    WINDOW *sub = subwin(stdscr, rows, cols, y, x);
    if (!sub)
    {
        endwin();
        fprintf(stderr, "Unable to create subwindow\n");
        return 1;
    }

    addstr("I'm in the standard screen (stdscr).");
    box(sub, 0, 0);
    mvwaddstr(sub, 1, 1, "I'm in a boxed subwindows.");
    
    refresh();
    getch();

    endwin();
    return 0;
}
