#include <locale.h>
#include <ncurses.h>

int main (void)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");

    // A rolagem de tela (scrolling) é um atributo da janela e pode estar ligado
    // ou desligado. Você também pode fazer a rolagem manual da tela por um dado
    // número de linhas.
    //
    // Por padrão a rolagem está desativada. Para ativar:
    //     scrollok(win, bf):
    //        win : janela
    //         bf : TRUE ou FALSE para ligar ou deligar a rolagem
    //
    // ATENÇÃO: o texto que é rolado para cima, na linha superior, é PERDIDO.
    
    initscr();
    scrollok(stdscr, TRUE);

    char text[] = "This is some wrapping. ";

    for (int x = 0; x < 300; x++)
    {
        addstr(text);
        napms(100);
        refresh();
    }

    getch();

    endwin();
    return 0;
}
