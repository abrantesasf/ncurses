#include <locale.h>
#include <ncurses.h>

int main (void)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    initscr();

    FILE *wfile;
    WINDOW *win;
    
    initscr();
    start_color();
    init_pair(1,COLOR_WHITE,COLOR_RED);
    refresh();
    
    wfile = fopen("window.win","r");
    if( wfile==NULL )
    {
        endwin();
        puts("Error reading file");
        return(1);
    }

    win = getwin(wfile);
    fclose(wfile);
    wrefresh(win);
    getch();

    endwin();
    return(0);
}
