#include <ncursesw/ncurses.h>

int main (void)
{
    initscr();

    addstr("This is the first line\n");
    addstr("Line two here\n");
    addstr("The third line\n");
    addstr("Fourth line here\n");
    addstr("And the fifth line\n");

    refresh();
    getch();

    // Para apagar um caractere por vez, usamos a função "delch()". Todos os
    // caracteres que estão à direita são deslocados 1 posição para a esquerda
    // e é criado um novo caractere em branco na última posição da linha. Essa
    // função não altera a posição do cursor!
    move(3, 7);
    for (int i = 0; i < 5; i++)
    {
        delch();
        refresh();
        napms(300);
    }

    getch();

    endwin();
    return 0;
}
