#include <ncursesw/ncurses.h>

int main (void)
{
    initscr();

    // Por padrão todas as chamadas à função getch() é BLOQUEANTE, ou seja, ela
    // pausa a execução do programa até que alguma tela seja pressionada. Se
    // quisermos alterar esse comportamento precisamos da função nodelay():
    //
    //     nodelay(win, bf), onde:
    //         win = qualquer janela ou screen válida
    //          bf = se TRUE,  DESATIVA o bloqueio
    //               se FALSE, ATIVA o bloqueio
    //
    // Se desativarmos o bloqueio getch() retorna uma tecla que estava na
    // aguardando na fila, ou o valor ERR.

    addstr("Press any key to begin:\n");
    refresh();
    getch();

    // DESLIGA o bloqueio de getch():
    nodelay(stdscr, TRUE);

    // Só termina o loop se o usuário digitar <espaço>:
    int value = 0;
    int c = '\0';
    while ((c = getch()) == ERR || c != ' ')
    {
        printw("%d\r", value++);
        refresh();
    }

    endwin();
    return 0;
}
