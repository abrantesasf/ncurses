#include <ncursesw/ncurses.h>
#include <locale.h>

int main (void)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    initscr();

    // O input de texto no Ncurses é buffered, ou seja, as funções de input
    // lêem o buffer ou testam se o buffer está vazio. Para esvaziar o buffer
    // de input, usamos a função flushinp();
    //
    // O uso de flushinp() é recomendado para esvaziar o buffer e limpar
    // keystrokes potencialmente indesejados que estejam no buffer, por exemplo:
    // antes de uma pergunta de S/N.
    size_t size = 80;
    char buffer[size + 1];

    addstr("Type. I'll wait...\n");
    refresh();
    napms(5000);

    addstr("Flushing buffer.\n");
    flushinp();
    addstr("Here is what you typed: \n");
    getnstr(buffer, size);

    endwin();
    return 0;
}
