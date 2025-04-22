#include <ncursesw/ncurses.h>
#include <locale.h>

int main (void)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    initscr();

    // Da mesma forma que getch(), a famíla de funções getstr() também é afetada
    // por diversas outras funções da Ncurses. Aqui está o efeito de noecho():
    int size = 30;
    char name[size + 1];
    char password[size + 1];

    addstr("Name: ");
    getnstr(name, size);
    
    noecho();
    addstr("Password: ");
    getnstr(password, size);
    
    echo();
    printw("%s's password is '%s'\n", name, password);
    refresh();
    getch();

    endwin();
    return 0;
}
