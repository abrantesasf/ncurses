#include <locale.h>
#include <ncursesw/ncurses.h>

int main (void)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    initscr();

    // O uso de subwindows em Ncurses é controverso: aguns dizem que é uma coisa
    // bugada e não deve ser usada, outros dizem que é útil e têm lugar. Os
    // principais "problemas" com as subwindows são:
    //     a) Elas usam o mesmo tipo de variável, WINDOW, e, mais ainda, a
    //        memória da subwindow é compartilhada com a memória da window pai.
    //        Isso quer dizer que, quando você coloca um caractere em uma
    //        subwindow está, ao mesmo tempo, colocando esse caractere na
    //        window pai.
    //     b) A subwindow conhece seu pai, mas o pai não tem nenhum conhecimento
    //        da subwindow. Se você tentar remover uma window que tem subwindow
    //        (o que é um ERRO) nenhum aviso será dado pois a window não tem
    //        ciência da existência da subwindow.
    //     c) Como a window e a subwindow compartilham memória, o texto escrito
    //        na subwindow também é escrito na window pai. Da mesma forma, o pai
    //        não tem nenhum "respeito" pela subwindow filha e pode facilmente
    //        sobrescrever o texto da subwindow. De fato, se um texto da janela
    //        pai sobrescrever um pedaço da subwindow, esse texto também se
    //        torna parte da subwindow.
    //
    // A maneira mais útil de pensar sobre uma subwindow é que ela é meramente
    // um modo conveniente de referenciar uma parte específica da window pai,
    // principalmente quando temos que fazer muitos cálculos de offsets e outros
    // cálculos semelhantes.
    //
    // As duas funções que CRIAM subwindows são as seguintes:
    //     subwin(win, rows, cols, y, x)
    //     derwin(win, rows, cols, y, x)
    // A diferença entre elas é que y e x na subwin são relativos ao stdscr, e
    // na derwin y e x são relativos à window pai.
    //
    // Quando uma subwindow é criada é retornado um ponteiro WINDOW (ou NULL).

    // Cria uma subwindow da stdscr:
    WINDOW *sub = subwin(stdscr, LINES-2, COLS-2, 1, 1);
    if (!sub)
    {
        endwin();
        fprintf(stderr, "Unable to create subwindow\n");
        return 1;
    }

    box(sub, 0, 0);
    mvwaddstr(sub, 1, 1, "I'm in a boxed subwindows.");
    
    refresh();
    getch();

    endwin();
    return 0;
}
