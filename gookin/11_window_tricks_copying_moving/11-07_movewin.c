#include <locale.h>
#include <ncursesw/ncurses.h>

int main (void)
{
    setlocale(LC_ALL, "pt_BR-UTF-8");

    // Também é possível mover uma janela para uma nova posição na tela, desde
    // que a nova posição seja suficiente para abranger toda a janela, ou seja,
    // a janela na nova posição deve caber totalmente dentro da tela. Para isso
    // usamos a função mvwin(win, line, col), onde "line" e "col" são relativos
    // à stdscr, com (0, 0) sendo o canto superior esquerdo. Algumas notas:
    //     a) Se a janela não couber totalmente na tela na nova posição, a
    //        função retorna ERR;
    //     b) Para completar a movimentação, a janela de background deve ser
    //        atualizada com touchwin() e refresh() (ou wrefresh());
    //     c) NÃO É POSSÍVEL MOVEL SUBWINDOWS, pois as subwindows compartilham
    //        memória com a window pai e isso faz com que o Ncurses não saiba
    //        atualizar que texto foi movido em qual janela;
    //     d) Não confunda mvwin(), que move uma janela, com wmove(), que move
    //        o cursor dentro de uma janela e
    //     e) Não é possível mover a stdscr.
    WINDOW *alpha;

    initscr();
    refresh();

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

    init_pair(1, COLOR_WHITE, COLOR_GREEN);

    alpha = newwin(7, 20, 3, 10);
    if(alpha == NULL)
    {
        endwin();
        fprintf(stderr, "Unable to create window\n");
        return 1;
    }

    wbkgd(alpha, COLOR_PAIR(1));
    mvwaddstr(alpha, 1, 2, "Window Alpha");
    wrefresh(alpha);
    getch();

    mvwin(alpha, 10, 43);
    mvwaddstr(alpha, 2, 2, "Moved!");
    touchwin(stdscr);
    refresh();
    wrefresh(alpha);
    getch();
    
    endwin();
    return 0;
}
