#include <ncursesw/ncurses.h>

int main (void)
{
    initscr();

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

    // A macro "insstr()" funciona como a "insch()", mas para uma string.
    // Seu argumento é uma string terminada por NUL. Ela insere 1 caractere
    // por vez (deslocando os caracteres à direita), mas para a string como um
    // todo, dando a impressão de que a string foi inserida como um bloco.
    move(1, 0);
    insstr("--> This is the new string! \n"); // ATENÇÃO: se insstr() receber um
                                              // \n, o comportamento padrão é
                                              // APAGAR o texto até o final da
                                              // linha!
    move(2, 0);
    insstr("--> This is the second new string!");

    refresh();
    getch();

    endwin();
    return 0;
}
