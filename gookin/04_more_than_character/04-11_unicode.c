#ifndef _XOPEN_SOURCE_EXTENDED
#define _XOPEN_SOURCE_EXTENDED 1
#endif

#include <locale.h>
#include <ncursesw/ncurses.h>

int main (void)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    initscr();

    // Ncurses pode fazer output Unicode, mas o processo não é tão simples. Os
    // requisitos são:
    //     1) A constante _XOPEN_SOURCE_EXTENDED deve ser definida como 1 antes
    //        do include de ncurses.h;
    //
    //     2) O locale do programa deve permitir Unicode (use a funçao setlocale
    //        da biblioteca locale.h); e
    //
    //     3) Deve-se utilizar a função de output de wide-char da Ncurses, a
    //        função add_wch(*wch). Note que o argumento dessa função é um
    //        ponteiro para uma estrutura cchar_t, uma struct com vários membros
    //        sendo os 2 de maior interesse agora os seguintes:
    //            typedef struct {
    //                attr_t   attr;
    //                wchar_t  chars[CCHARW_MAX];
    //            } cchar_t;
    //        O mebro "attr" é um atributo textual normal; o membro "chars" é
    //        um array de tamanho CCHARW_MAX (definido pelo Ncurses) que contém
    //        o code point Unicode do caractere especificado como um wide char
    //        (prefixo L). Para preencher corretamente todos os membros
    //
    // Para popular corretamente essa struct, devemos usar a seguinte função:
    //   setcchar(cchar_t *wcval, const wchar_t *wch, const attr_t attrs,
    //            short color_pair, const void *opts):
    //       wcval = ponteiro para o objeto cchar_t
    //       wch   = string de wchar_t (code point unicode) e terminada em L'\0'
    //       attrs = máscara de atributos do texto
    //  color_pair = número do par de cores
    //        opts = reservado para o futuro, deve ser passado como NULL
    //
    // Obs.: a função "add_wch" tem muitas variações, por exemplo:
    //     wadd_wch    = output de um caractere em uma janela específica
    //     mvadd_wch   = output em uma dada posição de linha/coluna
    //     mvwadd_wch  = output em uma janela em uma dada posição
    //     ...add_wch  = diversas outras funções
    cchar_t heart;
    setcchar(&heart, L"\u2665", A_NORMAL, 0, NULL);

    addstr("I ");
    add_wch(&heart);
    addstr(" Ncurses!");
    
    refresh();
    getch();

    endwin();
    return 0;
}
