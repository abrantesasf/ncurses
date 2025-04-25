#include <locale.h>
#include <ncurses.h>

int main (void)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    initscr();

    // Depois de inicializar, devemos usar 2 funções para ler o input do mouse:
    // a getch() e a getmouse(&musevent).
    //
    // getch() lê, além do teclado, os inputs do mouse. Os inputs do mouse são
    // definidos como o caractere KEY_MOUSE. Para que getch() consiga ler o
    // caractere KEY_MOUSE devemos usar a função keypad() para ativar a leitura
    // estendida de teclado. Também é interessante usar a função noecho() para
    // que o getch() não mostre "lixo" quando o mouse é lido.
    //
    // Depois que getch() detectar atividade do mouse, a função getmouse() é
    // usada para descobrirmos as informações sobre a atividade do mouse.
    // Em getmouse(&musevent), musevent é uma variável do tipo MEVENT, e é uma
    // struct cujos membros contém dados sobre as coordenadas e o evento.
    MEVENT mort;
    int ch;

    noecho();
    keypad(stdscr, TRUE);
    
    mousemask(ALL_MOUSE_EVENTS, NULL);

    while (1)
    {
        ch = getch();
        if (ch == KEY_MOUSE)
        {
            getmouse(&mort);
            move(0, 0);
            clrtoeol();
            printw("%d\t%d", mort.y, mort.x);
            refresh();
            continue;
        }
        if (ch == '\n')
            break;
    }

    endwin();
    return 0;
}
