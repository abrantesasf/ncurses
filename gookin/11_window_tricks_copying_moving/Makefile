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
	    11-01_overwrite \
	    11-02_overwrite2 \
	    11-03_overlay \
	    11-04_copywin \
	    11-05_clobber \
	    11-06_dup \
	    11-07_movewin


# ******************************************************************************
# Regra padrão: compila todos os programas (NÃO ALTERE!)
all: $(PROGRAMAS)


# ******************************************************************************
# Regras individuais de compilação: crie as regras específicas de cada target:
11-01_overwrite: 11-01_overwrite.c
	$(CC) $(CFLAGS) -o 11-01_overwrite 11-01_overwrite.c $(LFLAGS)

11-02_overwrite2: 11-02_overwrite2.c
	$(CC) $(CFLAGS) -o 11-02_overwrite2 11-02_overwrite2.c $(LFLAGS)

11-03_overlay: 11-03_overlay.c
	$(CC) $(CFLAGS) -o 11-03_overlay 11-03_overlay.c $(LFLAGS)

11-04_copywin: 11-04_copywin.c
	$(CC) $(CFLAGS) -o 11-04_copywin 11-04_copywin.c $(LFLAGS)

11-05_clobber: 11-05_clobber.c
	$(CC) $(CFLAGS) -o 11-05_clobber 11-05_clobber.c $(LFLAGS)

11-06_dup: 11-06_dup.c
	$(CC) $(CFLAGS) -o 11-06_dup 11-06_dup.c $(LFLAGS)

11-07_movewin: 11-07_movewin.c
	$(CC) $(CFLAGS) -o 11-07_movewin 11-07_movewin.c $(LFLAGS)


# ******************************************************************************
# Regras para a limpeza final (NÃO ALTERE!)
limpar:
	rm -f *~ a.out core graphics.ps

apagar: limpar
	rm -f *.o *.a $(PROGRAMAS)
