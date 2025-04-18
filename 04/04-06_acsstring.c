#include <ncursesw/ncurses.h>

int main (void)
{
    initscr();

    // Podemos exibir uma string de caracteres ACS, mas o resultado é um pouco
    // imprevisível pois, dependendo dos caracteres normais alternativos que
    // substituem os ACS não disponíveis em seu terminal, o resultado final
    // será um "tiro no escuro":
    attrset(A_ALTCHARSET);
    addstr("Hello there!");
    
    refresh();
    getch();

    endwin();
    return 0;
}
