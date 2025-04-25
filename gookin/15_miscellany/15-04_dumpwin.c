#include <locale.h>
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>


int main (void)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    initscr();

    char word[7];
    int x,w,r;
    
    srandom((unsigned) time(NULL));
    word[6] = '\0';
        
    for(x = 0; x < 200; x++)
    {
        for(w = 0; w < 6;w++)
            word[w] = (random() % 26) + 'a';
        printw("%s\t", word);
    }
    addstr("\nPress Enter to dump the screen");
    refresh();
    getch();

    r = scr_dump("dump.win");
    if(r == ERR)
        addstr("Error writing window");
    else
        addstr("File written; press Enter");
    refresh();
    getch();

    endwin();
    return 0;
}
