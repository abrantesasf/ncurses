#include <ncursesw/ncurses.h>
#include <string.h>

void center (int row, char *title);

int main (void)
{
    initscr();

    // Uma das coisas mais básicas a se fazer é centralizar algum texto. Neste
    // programa definimos o procedimento "center" para fazer isso, e apenas
    // usamos esse procedimento:
    center(1, "Penguin Soccer Finals");
    center(5, "Cattle Dung Samples from Temecula");
    center(7, "Catatonic Theater");
    center(9, "Why do Ions Hate Each Other?");

    getch();

    endwin();
    return 0;
}

void center (int row, char *title)
{
    // O cálculo para centralizar é padrão em qualquer aplicação "gráfica", só
    // fazer:
    //
    //            (<tamanho da janela> - <tamanho do texto>) / 2
    //
    // Não foi incluído neste procedimentos diversas checagens prévias que
    // devem ser feitas, por exemplo:
    //     a) Verificar se o texto é maior do que a janela;
    //     b) Verificar se row é válido para o termianl;
    //     c) Verificar se title é ponteiro NULL;
    //     d) Verificar se offset será negativo;
    //     e) ...
    int len, offset, y, x;
    getmaxyx(stdscr, y, x);
    len = strlen(title);
    offset = (x - len)/2;
    mvaddstr(row, offset, title);
    refresh();
}
