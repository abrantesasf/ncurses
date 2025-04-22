#include <locale.h>
#include <ncursesw/ncurses.h>

int main (void)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    initscr();

    // Ncurses é um ambiente de janelas que, na verdade, são arrays de
    // caracteres exibidos em uma série de linhas e colunas no terminal.
    // Todas as funções que fazem o output de texto recebem como um dos
    // argumentos a janela na qual os caracteres devem aparecer. Isso é verdade
    // mesmo para as macros, por exemplo: addstr("texto") é, na verdade,
    // expandida para waddstr(stdscr, "texto").
    //
    // O prefixo "w" no nome da função indica que ela precisa receber uma janela
    // como argumento. O prefixo "mv" indica que a função precisa receber as
    // coordenadas y e x (para o move) e o prefixo "mvw" indica que a função
    // precisa da janela e das coordenadas. Algumas funções não seguem esse
    // padrão por motivos históricos.
    //
    // A função initscr() cria a stdscr, mas podemos criar nossas próprias
    // janelas com a função newwin():
    //     newwin(rows, cols, y_org, x_org)
    //
    // A maior janela possível tem o tamanho da stdscr e a menor 1 caractere. A
    // função newwin retorna um ponteiro para um estrutura WINDOW que já deve
    // existir no programa. Se newwin falhar, retorna NULL.
    //
    // Para especificar uma janela com o mesmo tamanho da stdscr, basta passar
    // 0 (zero) em todos os argumentos de newwin. Note que as novas janelas não
    // são exibidas até que sofram o refresh, feito com "wrefresh(janela)".
    WINDOW *another;

    addstr("This is the standard screen\n");
    refresh();
    getch();

    another = newwin(0,0,0,0);
    if( another == NULL)
    {
        addstr("Unable to create window");
        refresh();
        getch();
    }
    else
    {
        waddstr(another,"This is another window");
        wrefresh(another);
        wgetch(another);
    }

    endwin();
    return 0;
}
