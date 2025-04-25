#include <locale.h>
#include <ncurses.h>

int main (void)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    initscr();

    // Da mesma maneira que uma window pode ter subwindows, um pad pode ter
    // subpads. Da mesma maneira que com as windows, os subpads são melhor
    // utilizados como um offset em relação ao pad pai. Assim, se você está
    // trabalhando em uma certa parte do pad, você pode rapidamente criar um
    // subpad para evitar cálculos matemáticos.
    //
    //     subpad(p, rows, cols, y, x)
    //        p = pad pai
    //        rows e cols = tamanho do subpad
    //        y e x = posição do subpad relativo ao pad pai
    //
    // ATENÇÃO: da mesma maneira que as subwindows, os subpads compartilham
    // memória com o pad pai! Assim, alterar o conteúdo de um subpad causa a
    // alteração do texto no pad pai também.
    WINDOW *pop, *son;

    pop = newpad(50, 100);
    if (!pop)
    {
        endwin();
        fprintf(stderr, "Unable to create pad.\n");
        return 1;
    }

    for (int i = 0; i < 500; i++)
        waddstr(pop, "Hello ");

    son = subpad(pop, 10, 10, 0, 0);
    if (!son)
    {
        endwin();
        fprintf(stderr, "Unable to create subpad.\n");
        return 1;
    }
    
    addstr("Press Enter to update");
    refresh();
    getch();

    prefresh(son, 0, 0, 5, 5, 15, 15);
    getch();

    endwin();
    return 0;
}
