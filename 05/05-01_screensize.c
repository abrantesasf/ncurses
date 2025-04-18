#include <ncursesw/ncurses.h>

int main (void)
{
    initscr();

    // Para descobrir o tamanho da janela, existe a macro "getmaxyx(win, y, x)"
    // que tem os seguintes argumentos:
    //     win = janela a ser consultada
    //       y = variável inteira que receberá o número de linhas
    //       x = variável inteira que receberá o número de colunas
    // Note que x e y começam em 1 e vão até N, e são variáveis comuns, NÃO SÃO
    // ponteiros. Não é necessário passar ponteiros pois a macro getmaxyx é
    // reescrita para utilizar as variáveis de modo adequado.
    int x, y;
    getmaxyx(stdscr, y, x);

    printw("Window is %d rows by %d columns.\n", y, x);
    
    refresh();
    getch();

    endwin();
    return 0;
}
