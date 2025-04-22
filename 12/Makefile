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
	    12-01_scrolling \
	    12-02_scrolling2 \
	    12-03_scrollsub \
	    12-04_scroll \
	    12-05_scrup3 \
	    12-06_scrollreg


# ******************************************************************************
# Regra padrão: compila todos os programas (NÃO ALTERE!)
all: $(PROGRAMAS)


# ******************************************************************************
# Regras individuais de compilação: crie as regras específicas de cada target:
12-01_scrolling: 12-01_scrolling.c
	$(CC) $(CFLAGS) -o 12-01_scrolling 12-01_scrolling.c $(LFLAGS)

12-02_scrolling2: 12-02_scrolling2.c
	$(CC) $(CFLAGS) -o 12-02_scrolling2 12-02_scrolling2.c $(LFLAGS)

12-03_scrollsub: 12-03_scrollsub.c
	$(CC) $(CFLAGS) -o 12-03_scrollsub 12-03_scrollsub.c $(LFLAGS)

12-04_scroll: 12-04_scroll.c
	$(CC) $(CFLAGS) -o 12-04_scroll 12-04_scroll.c $(LFLAGS)

12-05_scrup3: 12-05_scrup3.c
	$(CC) $(CFLAGS) -o 12-05_scrup3 12-05_scrup3.c $(LFLAGS)

12-06_scrollreg: 12-06_scrollreg.c
	$(CC) $(CFLAGS) -o 12-06_scrollreg 12-06_scrollreg.c $(LFLAGS)


# ******************************************************************************
# Regras para a limpeza final (NÃO ALTERE!)
limpar:
	rm -f *~ a.out core graphics.ps

apagar: limpar
	rm -f *.o *.a $(PROGRAMAS)
