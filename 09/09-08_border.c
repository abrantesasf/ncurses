#include <locale.h>
#include <ncursesw/ncurses.h>

int main (void)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    initscr();

    // Ncurses oferece funções para acrescentar bordas às janelas:
    //     wborder
    //     border
    //     box
    //
    // Para desenhar as bordas são usados caracteres ACS (ou aproximações ASCII)
    // se os ACS não estiverem disponíveis.
    //
    // Os caracteres das bordas não são protegidos e aparecem nas linhas e
    // colunas externas das janelas. Tenha cuidado para não sobrescrever os
    // caracteres (use um offset ou uma subwindow).
    //
    // Essas funções recebem, pelo menos, 8 argumentos. Exemplo:
    //     border(caractere da borda esquerda,
    //            caractere da borda direita,
    //            caractere da borda superior,
    //            caractere da borda inferior,
    //            caractere da esquina superior esquerda,
    //            caractere da esquina superior direita,
    //            caractere da esquina inferior esquerda,
    //            caractere da esquina inferior direita);
    //
    // Para criar uma borda simples, passe 0 em todos os argumentos.
    //
    // Cuidado com \n ao usar bordas pois, como já vimos, o comportamento parão
    // de \n não é só quebrar uma linha, ele APAGA todos os caracteres do cursor
    // até o final da linha e pode apagar a borda também.
    border(0, 0, 0, 0, 0, 0, 0, 0);
    move(1, 1);
    addstr("Now that's a swell border!");
    move(2, 1);
    
    refresh();
    getch();
    
    endwin();
    return 0;
}
