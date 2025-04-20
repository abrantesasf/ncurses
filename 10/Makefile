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
	    10-01_sub1 \
	    10-02_sub2 \
	    10-03_sub3 \
	    10-04_subsub \
	    10-05_delsub


# ******************************************************************************
# Regra padrão: compila todos os programas (NÃO ALTERE!)
all: $(PROGRAMAS)


# ******************************************************************************
# Regras individuais de compilação: crie as regras específicas de cada target:
10-01_sub1: 10-01_sub1.c
	$(CC) $(CFLAGS) -o 10-01_sub1 10-01_sub1.c $(LFLAGS)

10-02_sub2: 10-02_sub2.c
	$(CC) $(CFLAGS) -o 10-02_sub2 10-02_sub2.c $(LFLAGS)

10-03_sub3: 10-03_sub3.c
	$(CC) $(CFLAGS) -o 10-03_sub3 10-03_sub3.c $(LFLAGS)

10-04_subsub: 10-04_subsub.c
	$(CC) $(CFLAGS) -o 10-04_subsub 10-04_subsub.c $(LFLAGS)

10-05_delsub: 10-05_delsub.c
	$(CC) $(CFLAGS) -o 10-05_delsub 10-05_delsub.c $(LFLAGS)


# ******************************************************************************
# Regras para a limpeza final (NÃO ALTERE!)
limpar:
	rm -f *~ a.out core graphics.ps

apagar: limpar
	rm -f *.o *.a $(PROGRAMAS)
