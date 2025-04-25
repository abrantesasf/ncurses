#include <locale.h>
#include <ncurses.h>

int main (void)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    initscr();

    FILE *wfile;
    WINDOW *win;

    start_color();
    init_pair(1,COLOR_WHITE,COLOR_BLUE);
    refresh();

    win = newwin(3,10,7,30);
    wbkgd(win,COLOR_PAIR(1));
    box(win,0,0);
    mvwaddstr(win,1,2,"Window");
    wrefresh(win);
    getch();
    
    wfile = fopen("window.win","w");
    if( wfile==NULL )
    {
        endwin();
        puts("File creation error");
        return(1);
    }

    int r = putwin(win,wfile);
    fclose(wfile);
    addstr("Window data written");
    refresh();
    getch();

    endwin();
    return(0);
}
