#include <ncursesw/ncurses.h>

int main (void)
{
    initscr();

    // Ncurses usa uma variável de um tipo especial, o tipo "chtype", que tem
    // 32 bits e serve para armazenar um caractere com seus atributos de texto,
    // atributos de cor e outros. Esses dados ficam armazenados junto com o
    // caractere e ficam com o caractere, mesmo que sejam usadas funções do
    // Ncurses para copiar o texto.
    //
    // A maneira mais comum de criar um chtype é usar bitwise OR para
    // "imprimir" na tela o caractere chtype:
    addch('c');
    addch('a' | A_BOLD);
    addch('t' | A_REVERSE);
    
    refresh();
    getch();

    endwin();
    return 0;
}
