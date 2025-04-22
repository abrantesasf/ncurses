#include <ncursesw/ncurses.h>

int main (void)
{
    int yoda = 874;
    int ss = 65;
    
    initscr();

    // printw é exatamente a mesma coisa que printf de C:
    printw("Yoda is %d years old.\n", yoda);
    printw("He has collected %d years ", yoda - ss);
    printw("of Social Security.\n");

    refresh();
    getch();

    endwin();
    return 0;
}
