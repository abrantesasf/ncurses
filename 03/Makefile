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
	    03-01_twinkle \
	    03-02_annoy \
	    03-03_colortest \
	    03-04_yellowred \
	    03-05_colorful \
	    03-06_pink \
	    03-07_bgcolor1 \
	    03-07_bgcolor1_v2 \
	    03-08_bgcolor2 \
	    03-09_notice


# ******************************************************************************
# Regra padrão: compila todos os programas (NÃO ALTERE!)
all: $(PROGRAMAS)


# ******************************************************************************
# Regras individuais de compilação: crie as regras específicas de cada target:
03-01_twinkle: 03-01_twinkle.c
	$(CC) $(CFLAGS) -o 03-01_twinkle 03-01_twinkle.c $(LFLAGS)

03-02_annoy: 03-02_annoy.c
	$(CC) $(CFLAGS) -o 03-02_annoy 03-02_annoy.c $(LFLAGS)

03-03_colortest: 03-03_colortest.c
	$(CC) $(CFLAGS) -o 03-03_colortest 03-03_colortest.c $(LFLAGS)

03-04_yellowred: 03-04_yellowred.c
	$(CC) $(CFLAGS) -o 03-04_yellowred 03-04_yellowred.c $(LFLAGS)

03-05_colorful: 03-05_colorful.c
	$(CC) $(CFLAGS) -o 03-05_colorful 03-05_colorful.c $(LFLAGS)

03-06_pink: 03-06_pink.c
	$(CC) $(CFLAGS) -o 03-06_pink 03-06_pink.c $(LFLAGS)

03-07_bgcolor1: 03-07_bgcolor1.c
	$(CC) $(CFLAGS) -o 03-07_bgcolor1 03-07_bgcolor1.c $(LFLAGS)

03-07_bgcolor1_v2: 03-07_bgcolor1_v2.c
	$(CC) $(CFLAGS) -o 03-07_bgcolor1_v2 03-07_bgcolor1_v2.c $(LFLAGS)

03-08_bgcolor2: 03-08_bgcolor2.c
	$(CC) $(CFLAGS) -o 03-08_bgcolor2 03-08_bgcolor2.c $(LFLAGS)

03-09_notice: 03-09_notice.c
	$(CC) $(CFLAGS) -o 03-09_notice 03-09_notice.c $(LFLAGS)


# ******************************************************************************
# Regras para a limpeza final (NÃO ALTERE!)
limpar:
	rm -f *~ a.out core graphics.ps

apagar: limpar
	rm -f *.o *.a $(PROGRAMAS)
