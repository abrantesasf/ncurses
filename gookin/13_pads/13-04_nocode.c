#include <locale.h>
#include <ncurses.h>

int main (void)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    initscr();

    // Pads não são muito utilizados. Uma funcionalidade útil é carregar um
    // texto e depois mostrar pedaços desse texto na stdscr, o que pode ser útil
    // ao exibir texto de ajuda por exemplo.
    //
    // Para remover um pad use a função: delwin(pad). Isso também pode ser
    // utilizado para remover subpads. ATENÇÃO: remova o subpad ANTES de remover
    // o pad pai.
    //
    // ATENÇÃO: as seguintes funções de windows não podem ser usadas com pads:
    //    mvwin
    //    scroll
    //    scrl
    //    subwin
    //    wrefresh
    //    wnoutrefresh

    endwin();
    return 0;
}
