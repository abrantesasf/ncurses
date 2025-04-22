#include <ncursesw/ncurses.h>

int main (void)
{
    initscr();

    if (!has_colors())
    {
        endwin();
        fprintf(stderr, "Terminal cannot do colors.\n");
        return 1;
    }
    if (start_color() != OK)
    {
        endwin();
        fprintf(stderr, "Unable to start colors.\n");
        return 1;
    }

    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    
    // A função bkgd() também serve para atribuir qualquer atributo de texto à
    // toda tela, pois seu argumento é um caractere do tipo CHTYPE, um tipo
    // especial do Ncurses que inclui as duas coisas, o próprio caractere e as
    // informações dos atributos. Podemos usar como background para a janela
    // um caractere como um ponto, por exemplo:
    //     bkgd('.');
    // Mas também podemos fazer bitwise OR para passar os outros atributos:
    bkgd(COLOR_PAIR(1) | '.');

    attron(A_BOLD);
    addstr("This is some text.\n");

    refresh();
    getch();

    endwin();
    return 0;
}
