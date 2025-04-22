#include <ncursesw/ncurses.h>

int main (void)
{
    initscr();

    char text1[] = "This is the first line\n";
    char text2[] = "Line two here\n";
    char text3[] = "The third line\n";
    char text4[] = "Fourth line here\n";
    char text5[] = "And the fifth line\n";

    addstr(text1);
    addstr(text2);
    addstr(text3);
    addstr(text4);
    addstr(text5);

    move(1, 0);       // Vai para 2ª linha
    insertln();       // Insere uma linha em branco
    
    refresh();
    getch();

    addstr("This is the new line!");
    refresh();
    getch();

    endwin();
    return 0;
}
