#include <locale.h>
#include <ncurses.h>

int main (void)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");

    // A continuação do texto ao final de uma linha (wrapping) e ao final da
    // tela ocorrem de maneira previsível: ao final de uma linha o texto
    // continua na linha de baixo; ao final da tela a tela é "rolada" para cima
    // por 1 linha, a linha superior é perdida e uma nova linha inferior é
    // criada para continuar o texto.
    //
    // Obs.: a rolagem para cima da tela não ocorre a menos que a rolagem para a
    //       stdscr esteja habilitada.
    //
    // O Ncurses coloca texto na tela um caractere por vez, avançando o cursor
    // em 1 posição e fazendo o wrapping conforme necessário. Algumas regras:
    //
    //     a) '\t': as tabulações fazem com que o cursor avance para a próxima
    //              parade de tabulação, geralmente a cada 8 caracteres. A
    //              variável global TABSTOP pode ajuster esse espaço;
    //     b) '\n': faz com que o cursor vá para o início da linha inferior,
    //              apagando qualquer resto de texto na linha da posição do \n
    //              até o final da linha. Se a rolagem da tela estiver ligada e
    //              o \n ocorre na última linha, a tela rola para cima 1 linha.
    //     c) '\r': faz com que o cursor volte para o início da linha atual.
    //     d) '\b': retorna o cursror 1 posição na linha, de forma não
    //              destrutiva.
    //     e) ASCII Control: os caracteres de controle do ASCII (0 até 31 e 127)
    //              (exceto os 4 citados acima) são exibidos com a notação de
    //              circunflexo e avançam o cursor 2 posições. Por exemplo: o
    //              ASCII 17 é exibido como ^Q e o 127 como ^?. O código 0 não
    //              exibe nada (tradicionalmente era ^@).
    initscr();

    char text[] = "This is some wrapping. ";

    for (int x = 0; x < 100; x++)
    {
        addstr(text);
        napms(100);
        refresh();
    }

    getch();

    endwin();
    return 0;
}
