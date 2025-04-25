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
	    14-01_mousetest \
	    14-02_mspy \
	    14-03_clickput \
	    14-04_bclick


# ******************************************************************************
# Regra padrão: compila todos os programas (NÃO ALTERE!)
all: $(PROGRAMAS)


# ******************************************************************************
# Regras individuais de compilação: crie as regras específicas de cada target:
14-01_mousetest: 14-01_mousetest.c
	$(CC) $(CFLAGS) -o 14-01_mousetest 14-01_mousetest.c $(LFLAGS)

14-02_mspy: 14-02_mspy.c
	$(CC) $(CFLAGS) -o 14-02_mspy 14-02_mspy.c $(LFLAGS)

14-03_clickput: 14-03_clickput.c
	$(CC) $(CFLAGS) -o 14-03_clickput 14-03_clickput.c $(LFLAGS)

14-04_bclick: 14-04_bclick.c
	$(CC) $(CFLAGS) -o 14-04_bclick 14-04_bclick.c $(LFLAGS)


# ******************************************************************************
# Regras para a limpeza final (NÃO ALTERE!)
limpar:
	rm -f *~ a.out core graphics.ps

apagar: limpar
	rm -f *.o *.a $(PROGRAMAS)
