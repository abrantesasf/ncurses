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

    // Para apagar uma linha de texto usamos a função deleteln(), que remove a
    // linha atual do cursor, fazendo as linhas abaixo se deslocarem para cima.
    // É criada uma linha em branco para preencher a última linha. Essa função
    // não afeta a posição do cursor.
    move(2, 0);
    deleteln();

    refresh();
    getch();

    endwin();
    return 0;
}
