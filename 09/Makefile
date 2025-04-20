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
	    09-01_anotherwin \
	    09-02_switch \
	    09-03_switchback \
	    09-04_touch \
	    09-05_halfpint \
	    09-06_quad \
	    09-07_twowin \
	    09-08_border \
	    09-09_aborder \
	    09-10_box \
	    09-11_quadborders


# ******************************************************************************
# Regra padrão: compila todos os programas (NÃO ALTERE!)
all: $(PROGRAMAS)


# ******************************************************************************
# Regras individuais de compilação: crie as regras específicas de cada target:
09-01_anotherwin: 09-01_anotherwin.c
	$(CC) $(CFLAGS) -o 09-01_anotherwin 09-01_anotherwin.c $(LFLAGS)

09-02_switch: 09-02_switch.c
	$(CC) $(CFLAGS) -o 09-02_switch 09-02_switch.c $(LFLAGS)

09-03_switchback: 09-03_switchback.c
	$(CC) $(CFLAGS) -o 09-03_switchback 09-03_switchback.c $(LFLAGS)

09-04_touch: 09-04_touch.c
	$(CC) $(CFLAGS) -o 09-04_touch 09-04_touch.c $(LFLAGS)

09-05_halfpint: 09-05_halfpint.c
	$(CC) $(CFLAGS) -o 09-05_halfpint 09-05_halfpint.c $(LFLAGS)

09-06_quad: 09-06_quad.c
	$(CC) $(CFLAGS) -o 09-06_quad 09-06_quad.c $(LFLAGS)

09-07_twowin: 09-07_twowin.c
	$(CC) $(CFLAGS) -o 09-07_twowin 09-07_twowin.c $(LFLAGS)

09-08_border: 09-08_border.c
	$(CC) $(CFLAGS) -o 09-08_border 09-08_border.c $(LFLAGS)

09-09_aborder: 09-09_aborder.c
	$(CC) $(CFLAGS) -o 09-09_aborder 09-09_aborder.c $(LFLAGS)

09-10_box: 09-10_box.c
	$(CC) $(CFLAGS) -o 09-10_box 09-10_box.c $(LFLAGS)

09-11_quadborders: 09-11_quadborders.c
	$(CC) $(CFLAGS) -o 09-11_quadborders 09-11_quadborders.c $(LFLAGS)


# ******************************************************************************
# Regras para a limpeza final (NÃO ALTERE!)
limpar:
	rm -f *~ a.out core graphics.ps

apagar: limpar
	rm -f *.o *.a $(PROGRAMAS)
