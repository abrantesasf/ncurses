#include <locale.h>
#include <ncurses.h>

int main (void)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");

    // O comportamento da rolagem de uma subwindow NÃO É HERDADO da janela pai,
    // ou seja, a rolagem deve ser ativada para cada janela ou subjanela.
    initscr();

    WINDOW *sub;
    char text[] = "Scroll away! ";

    sub = subwin(stdscr, 10, 30, 6, 24);
    if (!sub)
    {
        endwin();
        fprintf(stderr, "Unable to create subwindow");
        return 1;
    }
    scrollok(sub, TRUE);
    
    for (int x = 0; x < 40; x++)
    {
        waddstr(sub, text);
        napms(50);
        wrefresh(sub);
    }

    getch();

    endwin();
    return 0;
}
