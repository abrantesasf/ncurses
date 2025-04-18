#include <ncursesw/ncurses.h>

int main (void)
{
    initscr();

    // Atenção: apesar de Ncurses ter o tipo especial "chtype", não é possível
    // construir facilmente uma "string" de chtypes (o output não será correto).
    // Isso ocorre pois o chtype não é char, e um array de chtype não é string.
    //
    // É possível exibir uma "string" de chtype através de um loop que imprime
    // cada caractere individualmente:
    chtype string[] =
        {'H' | A_BOLD,    'e', 'l' | A_REVERSE,
         'l' | A_REVERSE, 'o', '!' | A_UNDERLINE,
         '\0'
        };

    int x = 0;
    while (string[x])
        addch(string[x++]);
    
    refresh();
    getch();

    endwin();
    return 0;
}
