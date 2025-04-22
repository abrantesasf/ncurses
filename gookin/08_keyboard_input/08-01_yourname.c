#include <ncursesw/ncurses.h>

int main (void)
{
    initscr();

    // O input para um programa C padrão pode NÃO vir do teclado e, portanto,
    // os programas em C tratam o input como um stream de dados não interativo
    // e, portanto, ele não "pausa".
    //
    // O input no Ncurses é lido diretamente do teclado e podemos fazer o código
    // esperar por uma tecla, escanear o buffer por um input ou verificar se
    // algum input está pendente.
    //
    // A funçao para ler um único caractere do teclado é a:
    //     getch()
    // Esse função aguarda por uma tecla do teclado ou busca a tecla na fila de
    // espera. Note que ela NÃO aguarda o usuário telar <enter>: qualquer letra
    // digitada é lida imediatamente. Ela também é afetada por outras funções do
    // Ncurses, tais como echo(), keypad() e nodelay(). Note que getch() faz um
    // refresh automático da tela para poder exibir o caractere.
    size_t size = 50;
    char name[size + 1];                // +1 para o NUL

    char c = '\0';
    do
    {
        clear();
        addstr("Enter your name: ");
        getnstr(name, size);
        move(1, 0);
        printw("Your name is %s. ", name);
        printw("Is this correct (Y/N)? ");
        c = getch();
    }
    while (c != 'y' && c != 'Y');

    move(2, 0);
    printw("Pleased to meet you, %s.\n", name);

    getch();

    endwin();
    return 0;
}
