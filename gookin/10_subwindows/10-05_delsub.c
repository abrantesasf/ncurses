#include <locale.h>
#include <ncursesw/ncurses.h>

int main (void)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    initscr();

    // A função delwin() remove uma janela nomeaa, seja ela uma window ou uma
    // subwindow. Da mesma maneira que a remoção de uma janela "pai", a remoção
    // de uma subwindow NÃO REMOVE seu conteúdo da tela. Qualquer texto escrito
    // na subwindow é inerentemente "herdado" pela janela pai, então nada é de
    // fato perdido.
    //
    // NUNCA REMOVA uma window pai que tem subwindows ativas!
    WINDOW *sub;

    if (!has_colors())
    {
        endwin();
        fprintf(stderr, "Terminal cannot do colors!\n");
        return 1;
    }
    if (start_color() != OK)
    {
        endwin();
        fprintf(stderr, "Unable to start colors!\n");
        return 1;
    }

    init_pair(1,COLOR_BLACK,COLOR_BLUE);

    sub = subwin(stdscr, LINES-10, COLS-10, 4, 5);
    if(!sub)
    {
        endwin();
        fprintf(stderr, "Unable to create subwindow");
        return 1;
    }

    for(int x = 0; x < 120; x++)
        addstr("standard screen ");
    wbkgd(sub, COLOR_PAIR(1));

    for(int x = 0; x < 200; x++)
        waddstr(sub," sub ");

    refresh();
    wrefresh(sub);
    getch();

    delwin(sub);
    mvaddstr(0, 0, "Subwindow deleted ");
    refresh();
    getch();

    endwin();
    return 0;
}
