#include <locale.h>
#include <ncurses.h>

int main (void)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");

    // A função scroll(win) só permite fazer a rolagem 1 linha de cada vez. Se
    // quisermos controlar a quantidade de linhas roladas, podemos usar a
    // função scrl(n), onde n representa a quantidade de linhas a serem roladas.
    // Há também a função wscrl(win, n), que especifica qual window fazer a
    // rolagem.
    //
    // ATEÇÃO: para que essas funções funcionem a rolagem deve estar habilitada
    // na window; se isso não for verdade as funções retornam ERR.
    //
    // A rolagem também pode ser NEGATIVA, situação na qual a tela rola para
    // baixo por n linhas. As linhas que rolaram para baixo da última linha são
    // perdidas.
    initscr();

    scrollok(stdscr, TRUE);
    
    for (int x = 0; x < LINES; x++)
        mvprintw(x, 0, "Line %2d", x);
    refresh();
    getch();

    scrl(3);
    refresh();
    getch();

    endwin();
    return 0;
}
