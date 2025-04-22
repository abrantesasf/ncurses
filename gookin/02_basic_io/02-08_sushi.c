#include <ncursesw/ncurses.h>

int main (void)
{
    int pieces;
    const float uni = 4.5F;

    initscr();

    addstr("SUSHI BAR");
    
    move(2, 0);
    printw("We have Uni today for %.2f.\n", uni);
    addstr("How many pieces would you like? ");
    refresh();

    scanw("%d", &pieces);
    printw("You want %d pieces?\n", pieces);
    printw("That will be $%.2f!\n", uni * pieces);

    refresh();
    getch();
    
    endwin();
    return 0;
}
