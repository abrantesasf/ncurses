#include <locale.h>
#include <ncurses.h>

int main (void)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    initscr();

    // Adicionar texto à um pad é simples: basta utilizar as funções de output
    // de texto do ncurses. A exibição desse texto é um pouco mais complicada:
    // temos que usar a função prefresh(). Efetivamente o que essa função faz é
    // copiar um PEDAÇO retangular de texto do pad para a stdscr.
    //
    //     prefresh(pad, pminrow, pmincol, sminrow, smincol, smaxrow, smaxcol)
    //        pad = ponteiro para o pad
    //        pminrow e pmincol = canto superior esquerdo do pedaço do pad
    //        sminrow e smincol = canto superior esquerdo da stdscr
    //        smaxrow e smaxcol = tamanho do retângulo a partir de (0, 0)
    //
    // Os argumentos smaxrow e smaxcol devem ser maiores que sminrow e smincol,
    // e eles devem cair dentro das dimensões do terminal. Mesmo que um pad
    // possa ser muito maior do que o terminal, o pedaço de texto a ser exibido
    // deve caber dentro das dimensões do terminal.
    //
    // A função prefresh() automaticamente faz o refresh da stdscr.
    WINDOW *p;

    p = newpad(50, 100);
    if (!p)
    {
        endwin();
        fprintf(stderr, "Unable to create pad.\n");
        return 1;
    }

    for (int i = 0; i < 500; i++)
        wprintw(p, "%4d", i);
    
    addstr("Press Enter to update");
    refresh();
    getch();

    prefresh(p, 0, 0, 5, 5, 16, 45);
    getch();

    endwin();
    return 0;
}
