#include <locale.h>
#include <ncurses.h>

int main (void)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    initscr();

    // Ncurses consegue trabalhar com o mouse, lendo a posição atual do mouse e
    // os eventos de seus botões como input. Os movimentos do mouse não são
    // monitorados.
    //
    // Para usar o mouse temos que confirmar que a versão do ncurses em uso está
    // capacitada para isso. Basta checar se a constante NCURSES_MOUSE_VERSION é
    // maior do que zero.
    //
    // Depois temos que determinar que eventos serão comunicados com a função:
    //     mousemask(newmask, *oldmask)
    //        newmask = constante que representa diversos eventos
    //        oldmask = valor de mousemask prévia (NULL na maioria dos casos)
    //
    // A constante newmask mais útil é a ALL_MOUSE_EVENTS, que monitora todos os
    // eventos do mouse, usados em cobinação ou não com Shift, Alt e Ctrl.
    //
    // O argumento newmask é uma variável do tipo mmask_t.
    if (NCURSES_MOUSE_VERSION > 0)
    {
        addstr("Mouse functions available.\n");
        mousemask(ALL_MOUSE_EVENTS, NULL);
        addstr("Mouse Active.\n");
    }
    else
    {
        addstr("Mouse functions unavailable.\n");
    }

    refresh();
    getch();

    endwin();
    return 0;
}
