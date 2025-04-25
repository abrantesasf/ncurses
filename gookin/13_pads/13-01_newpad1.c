#include <locale.h>
#include <ncurses.h>

int main (void)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    initscr();

    // Pads são úteis quando precisamos ter informações preparadas, mas não
    // apresentadas na tela. São estruturas de dados window que não são
    // limitadas pelas dimensões reais do terminal, ou seja: podemos criar pads
    // com 1 caracteres (1x1) até o máximo de memória que o computador suportar.
    // A função que cria pads é:
    //
    //     newpad(row, cols)
    //
    // A função retorna um ponteiro para WINDOW ou NULL se não houver memória
    // suficiente para a criação da pad.
    WINDOW *p;

    p = newpad(50, 100);
    if (!p)
    {
        endwin();
        fprintf(stderr, "Unable to create pad.\n");
        return 1;
    }

    addstr("New pad created");
    refresh();
    getch();

    endwin();
    return 0;
}
