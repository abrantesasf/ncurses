#include <ncursesw/ncurses.h>

int main (void)
{
    initscr();

    // As funções básicas para ajustar os atributos do texto em Ncurses, do
    // ponto onde a função foi chamada em diante, são:
    //
    //     attrset(attrs): configura um novo conjunto de atributos (attrs),
    //                     desligando todos os outros atributos previamente
    //                     habilitados.
    //
    //     attron(attrs): habilita um novo conjunto de atributos (attrs),
    //                    adicionando esses novos atributos aos atributos já
    //                    habilitados.
    //
    //     attroff(attrs): desliga o conjunto de atributos (attrs), mantendo
    //                     habilitados quaisquer atributos que já estão ativos
    //                     e que não foram selecionados para serem desligados.
    //
    //     standend(): macro sinônimo de "attrset(A_NORMAL)", utilizado para
    //                 desligar todos os atributos e voltar ao texto normal.
    //
    // Esses atributos afetam apenas o texto, não afetam o espaço em branco
    // entre as palavras. Principais atributos:
    //     A_ALTCHARSET          A_BLINK          A_BOLD
    //     A_DIM                 A_INVIS          A_NORMAL
    //     A_REVERSE             A_STANDOUT       A_UNDERLINE
    
    attron(A_BOLD);
    addstr("Twinkle, twinkle little star\n");
    attron(A_BLINK);
    addstr("How I wonder what you are.\n");
    attroff(A_BOLD);
    addstr("Up above the world so high,\n");
    addstr("Like a diamond in the sky.\n");
    attrset(A_REVERSE);
    addstr("Twinkle, twinkle little star\n");
    attrset(A_UNDERLINE);
    addstr("How I wonder what you are.\n");

    refresh();
    getch();

    endwin();
    return 0;
}
