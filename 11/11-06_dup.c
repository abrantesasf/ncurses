#include <locale.h>
#include <ncursesw/ncurses.h>

int main (void)
{
    setlocale(LC_ALL, "pt_BR-UTF-8");

    // É possível duplicar totalmente uma janela (tamanho, texto, atributos)
    // através da função dupwin(), que usa uma janela existente como um template
    // criar uma nova janela. Essa função retorna um ponteiro WINDOW para a
    // cópia.
    WINDOW *fred, *barney;
    
    initscr();
    refresh();
        
    fred = newwin(0, 0, 0, 0);
    waddstr(fred, "This is Fred.\n");
    wrefresh(fred);
    getch();
    
    barney = dupwin(fred);
    mvwaddstr(barney, 0, 0, "This is Barney.\n");
    wrefresh(barney);
    getch();
    
    waddstr(fred, "Nice to see you, Barney!\n");
    touchwin(fred);
    wrefresh(fred);
    getch();

    waddstr(barney, "Nice to see You too, Fred!\n");
    touchwin(barney);
    wrefresh(barney);
    getch();

    endwin();
    return 0;
}
