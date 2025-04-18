#include <ncursesw/ncurses.h>

int main (void)
{
    initscr();

    // Um array de chtype também pode conter caracteres ACS, pois os ACS também
    // são do tipo chtype. Mas aqui há um PROBLEMA: se tentarmos criar um array
    // de ACS para, por exemplo, desenhar uma caixa, e usarmos um loop para
    // imprimir cada caractere ACS, o output NÃO será o esperado:
    
    /* Esta trecho não funciona:
    chtype box[12] =
        {
            ACS_ULCORNER, ACS_HLINE, ACS_URCORNER, '\n',
            ACS_VLINE   , ' '      , ACS_VLINE,    '\n',
            ACS_LLCORNER, ACS_HLINE, ACS_LRCORNER, '\n'
        };
    int x = 0;
    while (box[x])
        addch(box[x++]);
    */

    // O problema é que as constantes ACS são expandidas em tempo de compilação
    // e o resultado não será útil no seu programa. A solução é usar os valores
    // ou caracteres ASCII que são atribuídos aos ACS, configurando o atributo
    // A_ALTCHARSET (individualmente para cada caractere ou como um todo para a
    // tela):
    char box[] = "lqk\nx x\nmqj\n"; // equivalentes aos ACS para uma caixa
                                    // tá de sacanagem...
    
    attrset(A_ALTCHARSET);
    addstr(box);
        
    refresh();
    getch();

    endwin();
    return 0;
}
