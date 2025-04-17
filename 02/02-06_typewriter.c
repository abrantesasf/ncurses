#include <ncursesw/ncurses.h>

int main (void)
{
    int ch;

    initscr();

    addstr("Type a few lines of text.\n");
    addstr("Press ~ to quit.\n");
    
    refresh();

    // getch() obtém o caractere que o usuário digitou e, AUTOMATICAMENTE,
    // faz o echo desse caractere na tela. É por isso que no loop abaixo
    // não é necessária nenhuma função para exibir o caractere obtido e
    // também não é necessário fazer o refresh.
    //
    // ATENÇÃO: em teclados ABNT ou ABNT2 a tecla '~' é uma "dead-key", ou seja,
    // ela não gera o byte 0x7E imediatamente: o caractere '~' só é enviado ao
    // programa quando pressionamos <space>. Assim, para sair do programa,
    // digite ~<space>.
    while ((ch = getch()) != '~')
        ;

    endwin();
    return 0;
}
