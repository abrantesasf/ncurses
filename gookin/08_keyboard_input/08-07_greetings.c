#include <ncursesw/ncurses.h>
#include <locale.h>

int main (void)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    initscr();

    // Para ler mais do que 1 único caractere temos que usar a família de
    // funções "getstr", como a própria getstr() ou a getnstr(buf, size).
    // O mais indicado é usar a getnstr(buf, size) para diminuir o risco de
    // buffer overflow: o argumento "size" indica o número de máximo de
    // caracteres (ou bytes??) que será armazenado. A própria Ncurses não
    // deixa digitar mais do que o valor de "size". ATENÇÃO: o "buf" deve
    // ter, pelo menos, 1 byte a mais do que "size", para o NUL.
    // Assim como a getch(), as funções getstr(), getnstr() e similares faz
    // um refresh automático da screen.
    int size = 30;
    char first[size + 1];
    char last[size + 1];

    addstr("First name: ");
    getnstr(first, size);
    addstr("Last name: ");
    getnstr(last, size);
    printw("Pleased to meet you, %s %s!\n", first, last);
    
    refresh();
    getch();

    endwin();
    return 0;
}
