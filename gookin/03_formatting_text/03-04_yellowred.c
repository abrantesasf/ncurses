#include <ncursesw/ncurses.h>

int main (void)
{
    initscr();

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

    // Um COLOR_PAIR é uma combinação de atributos que ajusta a cor do
    // foreground e do background. Eles são criados com:
    //
    //     init_pair(n, foreground, background), onde os argumentos são:
    //         n = número do color pair (você cria, de 1 até n COLOR_PAIRS)
    //         foreground = cor do foreground dada pelas constantes do Ncurses
    //         background = cor do background dada pelas constantes do Ncurses
    //
    // Depois que um color pair é criado, para ativar esse color pair em um
    // texto, basta usar:
    //
    //     attrset(COLOR_PAIR(n)), onde n é o número do color pair
    init_pair(1, COLOR_YELLOW, COLOR_RED);

    addstr("Normal text.\n");
    attrset(COLOR_PAIR(1));
    addstr("Colored text. Wee!\n");
    standend();
    addstr("Back to normal.");
    
    refresh();
    getch();
    
    endwin();
    return 0;
}
