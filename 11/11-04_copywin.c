#include <locale.h>
#include <ncursesw/ncurses.h>

int main (void)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");

    // As funções overwrite() e overlay() são simplificações da função copywin()
    // que é bem mais poderosa. A função copywin() tem os seguinte argumentos:
    //
    //     copywin(swin, dwin, srow, scol, drow, dcol, dxrow, dxcol, type);
    //        swin = janela de origem
    //        dwin = janela de destino
    //        srow = coordenada y na janela de origem
    //        scol = coordenada x na janela de origem
    //        drow = coordenada y na janela de destino
    //        dcol = coordenada x na janela de destino
    //        dxrow = a partir de dwor, copia até que linha?
    //        dxcol = a partir de dcol, copia até que coluna?
    //        type = se FALSE faz overwrite; se TRUE faz overlay
    //
    // ATENÇÃO 1: (drow, dcol) marcam a coordenada de início da cópia no dwin,
    //            correspondendo ao canto superior esquerdo;
    //            (dxrow, dxcol) marcam a coordenada de fim da cópia no dwin,
    //            correspondendo ao canto inferior direito;
    //            A combinação desses 2 pontos dá a dimensão da área que será
    //            copiada.
    //
    // ATENÇÃO 2: com copywin() a janelas de origem e destino NÃO PRECISAM mais
    //            estar sobrepostas!
    WINDOW *red, *blue;
    
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
    
    red = newwin(10, 24, 5, 10);
    blue = newwin(10, 24, 5, 40);
    if(!red || !blue)
    {
        endwin();
        fprintf(stderr, "Unable to create windows\n");
        return 1;
    }

    wbkgd(red, COLOR_PAIR(1));
    wbkgd(blue, COLOR_PAIR(2));

    for (int i = 0; i < 34; i++)
    {
        waddstr(red, "red    ");
        waddstr(blue, "   blue");
    }
    wrefresh(red);
    wrefresh(blue);
    getch();

    if(copywin(red, blue, 0, 0, 1, 4, 5, 10, TRUE) == OK)
    { 
        wrefresh(blue);
        getch();
    }
    
    endwin();
    return 0;
}
