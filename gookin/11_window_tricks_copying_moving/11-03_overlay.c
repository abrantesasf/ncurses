#include <locale.h>
#include <ncursesw/ncurses.h>

int main (void)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");

    // Que janela está no topo? A janela que teve o refresh mais recente está no
    // topo das demais.
    //
    // A função overlay() difere da overwrite() pois ela não é destrutiva: ela
    // apenas copia texto de uma janela para outra (não copia os demais
    // atributos) mas só nos espaços vazios (espaços) na janela de destino.
    WINDOW *red,*blue;
    
    initscr();
    refresh();

    if (!has_colors())
    {
        endwin();
        fprintf(stderr, "Terminal cannot do colors!\n");
        return 1;
    }
    if (start_color() != OK)
    {
        endwin();
        fprintf(stderr, "Unable to start colors!\n");
        return 1;
    }

    init_pair(1, COLOR_WHITE, COLOR_RED);
    init_pair(2, COLOR_WHITE, COLOR_BLUE);
    
    red = newwin(10, 24, 2, 22);
    blue = newwin(10, 24, 5, 32);  // uma parte sobrepõe a red
    if(!red || !blue)
    {
        endwin();
        fprintf(stderr, "Unable to create windows\n");
        return 1;
    }

    wbkgd(red, COLOR_PAIR(1));
    wbkgd(blue, COLOR_PAIR(2));

    for (int i = 0; i < 30; i++)
    {
        waddstr(red, "o e l y ");
        waddstr(blue, " r a   v");
    }
    wrefresh(red);
    wrefresh(blue);
    getch();

    // O comportamento exibido neste programa é diferente do comportamento que
    // está descrito no livro! No livro está escrito que só o texto é copiado e
    // que os demais atributos não são, mas este programa mostra que além do
    // texto, as cores da janela red também são copiadas para a janela blue, mas
    // de forma não destrutiva, ou seja: somente se janela blue tiver não for
    // um espaço.
    if(overlay(red, blue) == OK)
    { 
        wrefresh(blue);
        getch();
    }
    
    endwin();
    return 0;
}
