#include <ncursesw/ncurses.h>

int main (void)
{
    initscr();

    // Um array de chtype NÃO É uma string (pois um chtype não é um char), mas o
    // Ncurses tem uma função que nos permite interpretar um array de chtype
    // como se fosse uma string:
    //
    //     addchstr(string);
    //
    // A "string" (na verdade o array de chtype) deve ser terminado por '\0'!
    chtype string[] =
        {'H' | A_BOLD,    'e', 'l' | A_REVERSE,
         'l' | A_REVERSE, 'o', '!' | A_UNDERLINE,
         '\0'
        };

    addchstr(string);
        
    refresh();
    getch();

    endwin();
    return 0;
}
