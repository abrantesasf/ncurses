#include <locale.h>
#include <ncursesw/ncurses.h>

int main (void)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    initscr();

    // Lembre-se de que uma subwindow compartilha dados e memória com a window
    // pai. Funções como a addstr() colocam o texto na stdscr, não na subwindow.
    int rows = LINES - 2;
    int cols = COLS - 2;
    int y = 1;
    int x = 1;
    WINDOW *sub = subwin(stdscr, rows, cols, y, x);
    if (!sub)
    {
        endwin();
        fprintf(stderr, "Unable to create subwindow\n");
        return 1;
    }

    box(stdscr, 0, 0);
    addstr("I'm writing text\n");
    addstr("to the standard screen.");
    refresh();
    getch();

    wclear(sub);
    wrefresh(sub);
    getch();

    endwin();
    return 0;
}
