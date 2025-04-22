#include <ncursesw/ncurses.h>

int kbhit (void);

int main (void)
{
    initscr();

    // Ncurses conta com a função "ungetch" que retorna uma tecla (caractere)
    // à fila do teclado (de modo semelhante à função "ungetc", que retorna um
    // caractere ao input stream).
    //
    // Lembrando que se "nodelay" estiver TRUE a "getch" retorna imediatamente a
    // tecla ou ERR, podemos usar a "ungetch" para checar a fila do teclado
    // (para saber se há caracteres em espera) e devolver o caractere para a
    // fila após a checagem.

    addstr("Tap a key while I count...\n");
    for (int x = 1; x <= 20; x++)
    {
        printw("%2d ", x);
        refresh();
        napms(500);
        if (kbhit())
            break;
    }
    addstr("Done!\n");
    printw("You pressed the '%c' key\n", getch());

    refresh();
    getch();

    endwin();
    return 0;
}

/* check the keyboard queue */
int kbhit (void)
{
    // Desliga bloqueio e echo:
    nodelay(stdscr, TRUE);
    noecho();

    // Verifica se há input na fila do teclado:
    int c, r;
    c = getch();
    if (c == ERR)
        r = FALSE;
    else
    {
        r = TRUE;
        ungetch(c);
    }

    // Habilita bloqueio e echo:
    echo();
    nodelay(stdscr, FALSE);

    return r;
}
