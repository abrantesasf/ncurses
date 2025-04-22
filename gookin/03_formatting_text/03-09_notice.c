#include <ncursesw/ncurses.h>

int main (void)
{
    initscr();

    // Ncurses oferece 2 funcionalidades para chamar a atenção do usuário:
    //
    //     beep(): toca o beep do terminal
    //     flash(): pisca a tela (não disponível em todos os terminais e,
    //              nesse caso, toca o beep novamente)
    addstr("Attention!\n");
    beep();
    refresh();
    getch();

    addstr("I said, ATTENTION!\n");
    flash();
    refresh();
    getch();

    endwin();
    return 0;
}
