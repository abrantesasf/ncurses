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
	    06-01_text1 \
	    06-02_text2 \
	    06-03_text3 \
	    06-04_text4 \
	    06-05_marquee1 \
	    06-06_marquee2 \
	    06-07_text5 \
	    06-08_text6 \
	    06-09_text7 \
	    06-10_cat \
	    06-11_insdel


# ******************************************************************************
# Regra padrão: compila todos os programas (NÃO ALTERE!)
all: $(PROGRAMAS)


# ******************************************************************************
# Regras individuais de compilação: crie as regras específicas de cada target:
06-01_text1: 06-01_text1.c
	$(CC) $(CFLAGS) -o 06-01_text1 06-01_text1.c $(LFLAGS)

06-02_text2: 06-02_text2.c
	$(CC) $(CFLAGS) -o 06-02_text2 06-02_text2.c $(LFLAGS)

06-03_text3: 06-03_text3.c
	$(CC) $(CFLAGS) -o 06-03_text3 06-03_text3.c $(LFLAGS)

06-04_text4: 06-04_text4.c
	$(CC) $(CFLAGS) -o 06-04_text4 06-04_text4.c $(LFLAGS)

06-05_marquee1: 06-05_marquee1.c
	$(CC) $(CFLAGS) -o 06-05_marquee1 06-05_marquee1.c $(LFLAGS)

06-06_marquee2: 06-06_marquee2.c
	$(CC) $(CFLAGS) -o 06-06_marquee2 06-06_marquee2.c $(LFLAGS)

06-07_text5: 06-07_text5.c
	$(CC) $(CFLAGS) -o 06-07_text5 06-07_text5.c $(LFLAGS)

06-08_text6: 06-08_text6.c
	$(CC) $(CFLAGS) -o 06-08_text6 06-08_text6.c $(LFLAGS)

06-09_text7: 06-09_text7.c
	$(CC) $(CFLAGS) -o 06-09_text7 06-09_text7.c $(LFLAGS)

06-10_cat: 06-10_cat.c
	$(CC) $(CFLAGS) -o 06-10_cat 06-10_cat.c $(LFLAGS)

06-11_insdel: 06-11_insdel.c
	$(CC) $(CFLAGS) -o 06-11_insdel 06-11_insdel.c $(LFLAGS)


# ******************************************************************************
# Regras para a limpeza final (NÃO ALTERE!)
limpar:
	rm -f *~ a.out core graphics.ps

apagar: limpar
	rm -f *.o *.a $(PROGRAMAS)
