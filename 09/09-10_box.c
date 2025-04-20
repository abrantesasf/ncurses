#include <locale.h>
#include <ncursesw/ncurses.h>

int main (void)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    initscr();

    // A função box() é uma simplificação da função border, tendo apenas 3
    // parâmetros:
    //     box(janela, caractere vertical, caractere horizontal);
    //
    // Os cantos são criados com caracteres ACS padrão. Se os caracteres forem
    // informados como 0, a borda padrão ACS será desenhada.
    box(stdscr, ':', '.');
    move(1, 1);
    addstr("Now that's a strange border!");
    move(2, 1);
    
    refresh();
    getch();
    
    endwin();
    return 0;
}
