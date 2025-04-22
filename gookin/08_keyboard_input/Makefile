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
	    08-01_yourname \
	    08-02_keywait1 \
	    08-03_keywait2 \
	    08-04_secretkey \
	    08-05_kbhit \
	    08-06_arrowkeys \
	    08-07_greetings \
	    08-08_urpwd \
	    08-09_flush


# ******************************************************************************
# Regra padrão: compila todos os programas (NÃO ALTERE!)
all: $(PROGRAMAS)


# ******************************************************************************
# Regras individuais de compilação: crie as regras específicas de cada target:
08-01_yourname: 08-01_yourname.c
	$(CC) $(CFLAGS) -o 08-01_yourname 08-01_yourname.c $(LFLAGS)

08-02_keywait1: 08-02_keywait1.c
	$(CC) $(CFLAGS) -o 08-02_keywait1 08-02_keywait1.c $(LFLAGS)

08-03_keywait2: 08-03_keywait2.c
	$(CC) $(CFLAGS) -o 08-03_keywait2 08-03_keywait2.c $(LFLAGS)

08-04_secretkey: 08-04_secretkey.c
	$(CC) $(CFLAGS) -o 08-04_secretkey 08-04_secretkey.c $(LFLAGS)

08-05_kbhit: 08-05_kbhit.c
	$(CC) $(CFLAGS) -o 08-05_kbhit 08-05_kbhit.c $(LFLAGS)

08-06_arrowkeys: 08-06_arrowkeys.c
	$(CC) $(CFLAGS) -o 08-06_arrowkeys 08-06_arrowkeys.c $(LFLAGS)

08-07_greetings: 08-07_greetings.c
	$(CC) $(CFLAGS) -o 08-07_greetings 08-07_greetings.c $(LFLAGS)

08-08_urpwd: 08-08_urpwd.c
	$(CC) $(CFLAGS) -o 08-08_urpwd 08-08_urpwd.c $(LFLAGS)

08-09_flush: 08-09_flush.c
	$(CC) $(CFLAGS) -o 08-09_flush 08-09_flush.c $(LFLAGS)


# ******************************************************************************
# Regras para a limpeza final (NÃO ALTERE!)
limpar:
	rm -f *~ a.out core graphics.ps

apagar: limpar
	rm -f *.o *.a $(PROGRAMAS)
