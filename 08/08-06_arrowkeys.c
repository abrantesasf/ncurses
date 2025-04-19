#include <ncursesw/ncurses.h>

int main (void)
{
    initscr();

    // Todos as teclas do teclado, ao serem pressionadas, geram um código que
    // pode ser capturado pelas funções de leitura da Ncurses. Esse código é
    // retornado de duas formas principais:
    //     1) O código bruto (raw code)
    //     2) Um valor especial que foi "cooked" pelo sistema operacional
    // As teclas alfa-numéricas retornam o valor ASCII; as outras teclas podem
    // retorar um valor de 16 bits, um par de valores de 8 bits, ou uma
    // seqüência de escape. Nós podemos identificar que valor foi retornado
    // para identificar a tecla exata com a função keypad:
    //
    //     keypad(win, bf)    onde:
    //        win = janela ou screen
    //         bf = TRUE ou FALSE para ativar ou desativar o mapeamento de
    //              teclas
    keypad(stdscr, TRUE);

    int c = '\0';
    do
    {
        c = getch();
        switch (c)
        {
        case KEY_DOWN:
            addstr("Down\n");
            break;
        case KEY_UP:
            addstr("Up\n");
            break;
        case KEY_LEFT:
            addstr("Left\n");
            break;
        case KEY_RIGHT:
            addstr("Right\n");
            break;
        }
        refresh();
    }
    while (c != '\n');

    endwin();
    return 0;
}
