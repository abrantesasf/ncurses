#include <locale.h>
#include <ncursesw/ncurses.h>

int main (void)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    initscr();

    // Para remover uma janela usa-se a função delwin(), que libera o ponteiro
    // WINDOW. Note que o CONTEÚDO da janela removida CONTINUA aparecendo na
    // tela (até você remover), mas a janela não existe mais.
    WINDOW *one, *two;

    refresh();

    one = newwin(LINES, COLS/2, 0, 0);
    two = newwin(LINES, COLS/2, 0, COLS/2);
    if (!one || !two)
    {
        endwin();
        fprintf(stderr, "Unable to create windows\n");
        return 1;
    }

    wbkgd(one, '|');
    waddstr(one, "Window One\n");
    wbkgd(two, '*');
    waddstr(two, "Window Two\n");

    wrefresh(one);
    getch();
    wrefresh(two);
    getch();

    delwin(one);
    waddstr(two, "Window One deleted\n");
    wrefresh(two);
    getch();
    
    endwin();
    return 0;
}
