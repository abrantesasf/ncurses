#include <ncursesw/ncurses.h>

int main (void)
{
    int sfirst = 25;
    int slast = 70;

    char first[sfirst + 1];  // +1 garante espaço para o NUL character
    char last[slast + 1];

    initscr();

    // getnstr(b, s) recebe uma string de tamanho até "s" bytes e armazena no
    // buffer "b". Você deve garantir que "s" seja, pelo menos, 1 byte menor do
    // que o buffer, para o armazenamento do NUL character final. Uma coisa
    // interessante é que getnstr(b, s) bloqueia o input ao alcançar "s" bytes e
    // toca um beep do terminal para avisar o usuário que o limite de digitação
    // foi alcançado. O usuário pode usar backspace e del para ajustar o texto.
    addstr("What is your first name? ");
    refresh();
    getnstr(first, sfirst);
    
    addstr("What is your last name? ");
    refresh();
    getnstr(last, slast);

    printw("Pleased to meet you, %s %s!\n", first, last);
    refresh();
    
    getch();

    endwin();
    return 0;
}
