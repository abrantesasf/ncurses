#include <locale.h>
#include <ncursesw/ncurses.h>

int main (void)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    initscr();

    WINDOW *second = NULL;

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
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    init_pair(2, COLOR_WHITE, COLOR_RED);

    second = newwin(0, 0, 0, 0);
    if (!second)
    {
        endwin();
        fprintf(stderr, "Unable to create window\n");
        return 1;
    }
    wbkgd(second, COLOR_PAIR(2));
    waddstr(second, "This is the second window\n");

    bkgd(COLOR_PAIR(1));
    addstr("This is the standard screen\n");
    addstr("Press ENTER");
    refresh();
    getch();

    wrefresh(second);
    getch();

    // Aqui tentamos retornar para a tela padrão (stdscr) mas não ocorre nada!
    // Isso não é um bug, é o comportamento normal do Ncurses. Internamente a
    // função refresh() compara o buffer da janela com um buffer virtual que
    // contém o que o Ncurses acredita ser o estado atual da tela do terminal.
    // Apenas as DIFERENÇAS são escritas na tela. Quando os dois buffers são
    // idênticos, a atualização (e o refersh) não são executados. Por isso o
    // código nas duas linhas abaixo não faz nada:
    wrefresh(stdscr);
    getch();
    
    endwin();
    return 0;
}
