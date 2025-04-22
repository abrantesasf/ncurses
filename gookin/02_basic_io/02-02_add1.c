#include <ncursesw/ncurses.h>

int main (void)
{
    char text[] = "Greetings from Ncurses!";
    char *t = text;
    
    initscr();

    while (*t)
    {
        addch(*t++);    // adiciona 1 caractere na tela
        refresh();      // atualiza curscr com conteúdo de stdscr
        napms(100);     // faz um delay de 0.1 segundos
    }

    getch();            // aguarda tecla do usuário

    endwin();
    
    return 0;
}
