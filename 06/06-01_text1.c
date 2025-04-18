#include <ncursesw/ncurses.h>

int main (void)
{
    initscr();

    // As funções de output de texto na tela (addch, addstr, printw)
    // sobrescrevem qualquer texto que já esteja exibido. Para preservar o texto
    // deve-se "abrir um espaço" antes da inserção do novo texto. As duas
    // principais funções para isso são:
    //
    //     insertln() = insere uma linha em branco na posição da linha atual. O
    //                  restante vai para baixo (a última linha é perdida). A
    //                  posição do cursor não se altera.
    //
    //     insch()    = insere um caractere na posição atual do cursor,
    //                  deslocando os demais para a direita. O caractere mais à
    //                  direita é perdido. A posição do cursos vai para a coluna
    //                  seguinte.
    char text1[] = "This is the first line\n";
    char text2[] = "Line two here\n";
    char text3[] = "The third line\n";
    char text4[] = "Fourth line here\n";
    char text5[] = "And the fifth line\n";

    addstr(text1);
    addstr(text2);
    addstr(text3);
    addstr(text4);
    addstr(text5);
    
    refresh();
    getch();

    endwin();
    return 0;
}
