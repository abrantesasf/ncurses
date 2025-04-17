# ******************************************************************************
# Makefile padrão para o estudo do livro "Dan Gookin's Guide to Ncurses
# Programming". Maiores informações https://github.com/abrantesasf/ncurses/
#
# Por: Abrantes Araújo Silva Filho


# ******************************************************************************
# Variáveis importantes para ncursesw:
CC=gcc
CFLAGS=-D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600
LFLAGS=-Wl,-Bsymbolic-functions -lncursesw -ltinfo


# ******************************************************************************
# Programas a serem compilados (pode ser tudo em uma única linha, mas colocar um
# nome por linha facilita a exclusão e a visualização):
PROGRAMAS = \
	    01-01_goodbye \
	    01-01_goodbye_v2 \
	    01-01_goodbye_v3 \
	    01-01_goodbye_v4 \
	    01-02_goodbye_final


# ******************************************************************************
# Regra padrão: compila todos os programas (NÃO ALTERE!)
all: $(PROGRAMAS)


# ******************************************************************************
# Regras individuais de compilação: crie as regras específicas de cada target:
01-01_goodbye: 01-01_goodbye.c
	$(CC) $(CFLAGS) -o 01-01_goodbye 01-01_goodbye.c $(LFLAGS)

01-01_goodbye_v2: 01-01_goodbye_v2.c
	$(CC) $(CFLAGS) -o 01-01_goodbye_v2 01-01_goodbye_v2.c $(LFLAGS)

01-01_goodbye_v3: 01-01_goodbye_v3.c
	$(CC) $(CFLAGS) -o 01-01_goodbye_v3 01-01_goodbye_v3.c $(LFLAGS)

01-01_goodbye_v4: 01-01_goodbye_v4.c
	$(CC) $(CFLAGS) -o 01-01_goodbye_v4 01-01_goodbye_v4.c $(LFLAGS)

01-02_goodbye_final: 01-02_goodbye_final.c
	$(CC) $(CFLAGS) -o 01-02_goodbye_final 01-02_goodbye_final.c $(LFLAGS)


# ******************************************************************************
# Regras para a limpeza final (NÃO ALTERE!)
limpar:
	rm -f *~ a.out core graphics.ps

apagar: limpar
	rm -f *.o *.a $(PROGRAMAS)
