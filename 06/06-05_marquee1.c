#include <ncursesw/ncurses.h>
#include <string.h>

int main (void)
{
    initscr();

    char text[] = "Armstrong walks on moon!";
    char *t = text;

    int len = strlen(text);

    // A função "insch" insere um char ou um chtype em uma posição específica,
    // deslocando todos os caracteres da linha para a direita (o caractere da
    // ponta é descartado):
    while (len)
    {
        move(5, 5);               // insere no mesmo lugar
        insch(*(t + len - 1));    // de trás para frente
        refresh();
        napms(300);
        len--;
    }

    getch();

    endwin();
    return 0;
}
