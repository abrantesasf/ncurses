#ifndef _XOPEN_SOURCE_EXTENDED
#define _XOPEN_SOURCE_EXTENDED 1
#endif

#include <locale.h>
#include <ncursesw/ncurses.h>

int main (void)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    initscr();

    // Se quisermos imprimir uma string em Unicode, existem duas opções que
    // podem ser utilizadas: 1) usar um array de cchar_t e fazer a impressão
    // caractere por caractere; ou 2) usar um array de wchar_t padrão do C e
    // a função addwstr(string) da Ncurses! A segunda opção simplifica o uso
    // de strings Unicode (mas mantém as desvantagens de usar wchar_t padrão
    // da linguagem C).
    //
    // Como a maioria das funções de output Ncurses, também existem variações
    // da função addwstr (w, mv, wmv).
    wchar_t hello[] =
        {
            // "Hello" ou "Olá", em Russo:
            0x041f, 0x0440, 0x0438, 0x0432,
            0x0435, 0x0442, 0x0021, 0x0
        };

    attrset(A_BOLD);
    addwstr(hello);
    
    refresh();
    getch();

    endwin();
    return 0;
}
