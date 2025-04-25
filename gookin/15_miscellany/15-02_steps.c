#include <locale.h>
#include <ncurses.h>

int main (void)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    initscr();

    // Se quisermos desenhar linhas verticais ou horizontais, podemos usar as
    // seguintes funções:
    //
    //     hline(ch, n)
    //     vline(ch, n)
    //
    // Elas desenham linhas, a partir da posição atual do cursor, usando o
    // caractere "ch" por "n" caracteres.
    //
    // ATENÇÃO: elas NÃO ALTERAM a posição do cursor.
    //
    // Também existem as funções alternativas como mvhline, mvvline e outras.
    int maxy, maxx;
    getmaxyx(stdscr, maxy, maxx);
    
    for(int y = 0, x = 0; y < maxy; y++, x+=2)
    {
        move(y, x);
        hline(0, maxx - x);
        vline(0, maxy - y);
    }
    refresh();
    getch();

    endwin();
    return 0;
}
