#include <ncursesw/ncurses.h>

int main (void)
{
    initscr();

    // Podemos usar ACSs para criar uma caixa na tela (não faça isso em códigos
    // reais pois o Ncurses tem uma função própria para isso). Note que nos
    // exemplos abaixo não foi necessário ajustar o atributo A_ALTCHARSET pois,
    // ao usar os ACSs diretamente, os ACSs já incluem esse atributo.
    addch(ACS_ULCORNER);
    addch(ACS_HLINE);
    addch(ACS_URCORNER);
    addch('\n');
    addch(ACS_VLINE);
    addch(' ');
    addch(ACS_VLINE);
    addch('\n');
    addch(ACS_LLCORNER);
    addch(ACS_HLINE);
    addch(ACS_LRCORNER);
    addch('\n');
    
    refresh();
    getch();

    endwin();
    return 0;
}
