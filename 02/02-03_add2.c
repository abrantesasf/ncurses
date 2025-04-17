#include <ncursesw/ncurses.h>

int main (void)
{
    char t1[] = "Shall I compare thee";
    char t2[] = " to a summer's day?";
    
    initscr();

    // addstr adiciona uma string à tela, e não inclui \n ao final:
    addstr(t1);         // adiciona t1
    addstr(t2);         // adiciona t2

    refresh();
    getch();

    endwin();
    return 0;
}
