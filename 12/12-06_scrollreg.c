#include <locale.h>
#include <ncurses.h>

int main (void)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");

    // A rolagem de linhas, por padrão, afeta TODAS as linhas de texto em uma
    // janela. Podemos limitar uma certa região de linhas para sofrer a rolagem
    // com as funções:
    //     setscrreg(top, bottom)
    //     wsetscrreg(win, top, bottom)
    initscr();

    char text[] = "Scroll me! Scroll me! Scroll me! ";

    bkgd('.');
    scrollok(stdscr, TRUE);
    setscrreg(3, LINES - 3);
    
    for (int x = 0; x < 300; x++)
    {
        addstr(text);
        napms(25);
        refresh();
    }

    getch();

    endwin();
    return 0;
}
