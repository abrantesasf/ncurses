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
	    15-01_cursset \
	    15-02_steps \
	    15-03_plus \
	    15-04_dumpwin \
	    15-05_undump \
	    15-06_wputfile \
	    15-07_wgetfile


# ******************************************************************************
# Regra padrão: compila todos os programas (NÃO ALTERE!)
all: $(PROGRAMAS)


# ******************************************************************************
# Regras individuais de compilação: crie as regras específicas de cada target:
15-01_cursset: 15-01_cursset.c
	$(CC) $(CFLAGS) -o 15-01_cursset 15-01_cursset.c $(LFLAGS)

15-02_steps: 15-02_steps.c
	$(CC) $(CFLAGS) -o 15-02_steps 15-02_steps.c $(LFLAGS)

15-03_plus: 15-03_plus.c
	$(CC) $(CFLAGS) -o 15-03_plus 15-03_plus.c $(LFLAGS)

15-04_dumpwin: 15-04_dumpwin.c
	$(CC) $(CFLAGS) -o 15-04_dumpwin 15-04_dumpwin.c $(LFLAGS)

15-05_undump: 15-05_undump.c
	$(CC) $(CFLAGS) -o 15-05_undump 15-05_undump.c $(LFLAGS)

15-06_wputfile: 15-06_wputfile.c
	$(CC) $(CFLAGS) -o 15-06_wputfile 15-06_wputfile.c $(LFLAGS)

15-07_wgetfile: 15-07_wgetfile.c
	$(CC) $(CFLAGS) -o 15-07_wgetfile 15-07_wgetfile.c $(LFLAGS)


# ******************************************************************************
# Regras para a limpeza final (NÃO ALTERE!)
limpar:
	rm -f *~ a.out core graphics.ps

apagar: limpar
	rm -f *.o *.a *.win $(PROGRAMAS)
