#include <locale.h>
#include <ncursesw/ncurses.h>

int main (void)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");

    // No Ncurses as janelas não são apenas conteineres para texto e formatação,
    // são verdadeiras estruturas de dados que podem ser copiadas, duplicadas,
    // movidas e mais. Algumas das funções disponíveis para esses "truques" com
    // janelas são as seguintes:
    //
    //     copywin()   : permite o maior controle sobre o copy/paste
    //     overwrite() : atalho para copywin
    //     overlay()   : atalho para copywin
    //     dupwin()    : duplica uma janela
    //
    // A função overwrite copia texto e atributos de uma janela para outra, de
    // modo "destrutivo": overwrite(swin, dwin). Para que a cópia seja exexutada
    // com sucesso, as janelas devem se sobrepor. Retorna OK ou ERR.
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
    
    red = newwin(10, 20, 2, 22);
    blue = newwin(10, 20, 5, 32);  // uma parte sobrepõe a red
    if(!red || !blue)
    {
        endwin();
        fprintf(stderr, "Unable to create windows\n");
        return 1;
    }

    wbkgd(red, COLOR_PAIR(1) | 'r');
    wbkgd(blue, COLOR_PAIR(2) | 'b');
    wrefresh(red);
    wrefresh(blue);
    getch();

    if(overwrite(red, blue) == OK)
    {
        wrefresh(blue);
        getch();
    }
    
    endwin();
    return 0;
}
