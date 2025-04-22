#include <ncursesw/ncurses.h>

int main (void)
{
    initscr();

    // Além dos caracteres ASCII básicos o Ncurses oferece um conjunto de
    // caracteres alternativos conhecido por "Alternative Character Set" (ACS),
    // que são um conjunto de caracteres definidos previamente e acessíveis
    // através de constantes que começam com o prefixo "ACS_". Nem todos os
    // terminais são capazes de exibir os caracteres ACS.
    //
    // Para usarmos um ACS devemos especificar que o texto será um ACS e
    // especificar qual ACS queremos imprimir na tela.
    //
    // Existem também ACS que usar o tipo wide ou char_t, que são idênticos aos
    // ACS normais, mas são acessíveis pelo prefixo "WACS_" ou invés do "ACS_".
    addch(A_ALTCHARSET | ACS_PI);
    addstr(" = 3.14159");
    
    refresh();
    getch();

    endwin();
    return 0;
}
