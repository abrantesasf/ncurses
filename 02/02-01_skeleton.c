/**
 * Template para programas Ncurses.
 */

#include <ncursesw/ncurses.h>

int main (void)
{
    // Inicializa a sessão Ncurses (não "limpa" a tela), cria estruturas de
    // memória e intefaces entre o Ncurses e sistema de I/O do terminal. Cria
    // 2 "telas":
    //
    //     - standard screen: é a janela principal, com o mesmo tamanho do
    //                        terminal, e serve como output padrão do Ncurses;
    //                        é referenciada pela variável "stdscr". ATENÇÃO:
    //                        a stdscr não é a mesma coisa que a janela do
    //                        terminal, ou seja: tudo o que você escreve nela
    //                        não é exibido automaticamente no terminal (para
    //                        exibir você precisa fazer um "refresh" da stdscr).
    //
    //     - current screen:  é um buffer interno utilizado para monitorar as
    //                        diferenças entre o que está sendo exibido no
    //                        terminal e o stdscr; ela é referenciada pela
    //                        variável "curscr". Quando executamos um refresh
    //                        estamos atualizando curscr com o conteúdo (na
    //                        verdade as diferenças) de stdscr.
    //
    // Se seu terminal tiver a funcionalidade "rmcup", a tela atual do terminal
    // é salva e restaurada após o término do programa.
    initscr();

    /* AQUI VAI O CÓDIGO DO SEU PROGRAMA PRINCIPAL! */

    // Finaliza a sessão Ncurses. É imperativo fazer isso pois, se você não
    // terminar a sessão do Ncurses e sair do programa seu terminal terá
    // comportamento errático.
    endwin();
    
    return 0;
}
