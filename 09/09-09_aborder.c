#include <locale.h>
#include <ncursesw/ncurses.h>

int main (void)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    initscr();

    // Lembrete dos argumentos da função border:
    //     border(caractere da borda esquerda,
    //            caractere da borda direita,
    //            caractere da borda superior,
    //            caractere da borda inferior,
    //            caractere da canto superior esquerda,
    //            caractere da canto superior direita,
    //            caractere da canto inferior esquerda,
    //            caractere da canto inferior direita);
    border('|', '|', '-', '-', '+', '+', '+', '+');
    move(1, 1);
    addstr("Now that's a swell border!");
    move(2, 1);
    
    refresh();
    getch();
    
    endwin();
    return 0;
}
