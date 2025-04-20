#include <locale.h>
#include <ncursesw/ncurses.h>

int main (void)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    initscr();

    // Subwindows podem ter outras subwindows. Isso pode ser um pouco confuso
    // mas, se estamos precisando calcular offsets de offsets, isso pode ser
    // muito útil.
    WINDOW *grandpa, *father, *son;
    int gl, gc;

    refresh();    // Boa prática fazer refresh de stdscr antes das outras

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
    init_pair(2, COLOR_RED,   COLOR_YELLOW);
    init_pair(3, COLOR_BLACK, COLOR_GREEN);
        
    grandpa = newwin(LINES-4, COLS-10, 2, 5);
    if (!grandpa)
    {
        endwin();
        fprintf(stderr, "Unable to create grandpa window\n");
        return 1;
    }
    getmaxyx(grandpa, gl, gc);
    father = derwin(grandpa, gl/2, gc, gl/2, 0);
    son = derwin(father, gl/2, 3, 0, (gc-4)/2);
    if (!father || !son)
    {
        endwin();
        fprintf(stderr, "Unable to create father or son window\n");
        return 1;
    }
    
    wbkgd(grandpa, COLOR_PAIR(1));
    waddstr(grandpa, "I am Grandpa\n");

    wbkgd(father, COLOR_PAIR(2));
    waddstr(father, "I am Father\n");
    wclrtobot(father);

    wbkgd(son, COLOR_PAIR(3));
    waddstr(son, "I am the boy\n");
    wrefresh(grandpa);
    getch();
    
    endwin();
    return 0;
}
