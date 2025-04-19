# ******************************************************************************
# Makefile padrão para o estudo do livro "Dan Gookin's Guide to Ncurses
# Programming". Maiores informações https://github.com/abrantesasf/ncurses/
#
# Por: Abrantes Araújo Silva Filho


# ******************************************************************************
# Variáveis importantes para ncursesw:
CC=gcc
CFLAGS=-std=c17 -Wall -Werror -Wpedantic -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
LFLAGS=-Wl,-Bsymbolic-functions -lncursesw -ltinfo


# ******************************************************************************
# Programas a serem compilados (pode ser tudo em uma única linha, mas colocar um
# nome por linha facilita a exclusão e a visualização):
PROGRAMAS = \
	    07-01_cls \
	    07-02_clearline \
	    07-03_clearbot


# ******************************************************************************
# Regra padrão: compila todos os programas (NÃO ALTERE!)
all: $(PROGRAMAS)


# ******************************************************************************
# Regras individuais de compilação: crie as regras específicas de cada target:
07-01_cls: 07-01_cls.c
	$(CC) $(CFLAGS) -o 07-01_cls 07-01_cls.c $(LFLAGS)

07-02_clearline: 07-02_clearline.c
	$(CC) $(CFLAGS) -o 07-02_clearline 07-02_clearline.c $(LFLAGS)

07-03_clearbot: 07-03_clearbot.c
	$(CC) $(CFLAGS) -o 07-03_clearbot 07-03_clearbot.c $(LFLAGS)


# ******************************************************************************
# Regras para a limpeza final (NÃO ALTERE!)
limpar:
	rm -f *~ a.out core graphics.ps

apagar: limpar
	rm -f *.o *.a $(PROGRAMAS)
