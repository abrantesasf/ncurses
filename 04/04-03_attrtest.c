#include <ncursesw/ncurses.h>

int main (void)
{
    initscr();

    // Internamente, os 32 bits de um caractere chtype são organizados da
    // seguinte maneira:
    //     Bits 00 a 07:    código ASCII do caractere
    //     Bits 08 a 15:    valores das cores
    //     Bits 16 a 31:    atributos individuais do texto
    //
    // O output exato no terminal dependerá do emulador de terminais, pois
    // nem todos os terminais suportam todos os atributos. A máscara de bits dos
    // atributos textuais (posições 16 a 31) está detalhada na tabela 4.1.
    //
    // Importante 1: toda vez que caracteres E atributos são combinados na tela,
    // o output sempre será um chtype.
    //
    // Importante 2: pode-se utilizar outras máscaras de bits para manipular as
    // variáveis chtype; essas máscaras estão detalhadas na tabela 4.2.
    //
    // Importante 3: um conjunto adicional de atributos, do padrão XSI, está
    // disponível e usa os mesmos sufixos dos atributos das tabelas 4.1 e 4.2
    // citadas acima; a diferença é que o prefixo é "WA_" ao invés de "A_".
    attrset(A_STANDOUT);
    addstr("This is A_STANDOUT\n");
    attrset(A_UNDERLINE);
    addstr("This is A_UNDERLINE\n");
    attrset(A_REVERSE);
    addstr("This is A_REVERSE\n");
    attrset(A_BLINK);
    addstr("This is A_BLINK\n");
    attrset(A_DIM);
    addstr("This is A_DIM\n");
    attrset(A_BOLD);
    addstr("This is A_BOLD\n");
    attrset(A_ALTCHARSET);
    addstr("This is A_ALTCHARSET\n");
    attrset(A_INVIS);
    addstr("This is A_INVIS\n");
    attrset(A_PROTECT);
    addstr("This is A_PROTECT\n");
    attrset(A_HORIZONTAL);
    addstr("This is A_HORIZONTAL\n");
    attrset(A_LEFT);
    addstr("This is A_LEFT\n");
    attrset(A_LOW);
    addstr("This is A_LOW\n");
    attrset(A_RIGHT);
    addstr("This is A_RIGHT\n");
    attrset(A_TOP);
    addstr("This is A_TOP\n");
    attrset(A_VERTICAL);
    addstr("This is A_VERTICAL\n");
    refresh();
    getch();
    endwin();
    return 0;
}
