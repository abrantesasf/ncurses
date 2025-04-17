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
	    02-01_skeleton \
	    02-02_add1 \
	    02-03_add2 \
	    02-04_add3 \
	    02-05_yoda \
	    02-06_typewriter \
	    02-06_typewriter_v2 \
	    02-07_yourname \
	    02-08_sushi


# ******************************************************************************
# Regra padrão: compila todos os programas (NÃO ALTERE!)
all: $(PROGRAMAS)


# ******************************************************************************
# Regras individuais de compilação: crie as regras específicas de cada target:
02-01_skeleton: 02-01_skeleton.c
	$(CC) $(CFLAGS) -o 02-01_skeleton 02-01_skeleton.c $(LFLAGS)

02-02_add1: 02-02_add1.c
	$(CC) $(CFLAGS) -o 02-02_add1 02-02_add1.c $(LFLAGS)

02-03_add2: 02-03_add2.c
	$(CC) $(CFLAGS) -o 02-03_add2 02-03_add2.c $(LFLAGS)

02-04_add3: 02-04_add3.c
	$(CC) $(CFLAGS) -o 02-04_add3 02-04_add3.c $(LFLAGS)

02-05_yoda: 02-05_yoda.c
	$(CC) $(CFLAGS) -o 02-05_yoda 02-05_yoda.c $(LFLAGS)

02-06_typewriter: 02-06_typewriter.c
	$(CC) $(CFLAGS) -o 02-06_typewriter 02-06_typewriter.c $(LFLAGS)

02-06_typewriter_v2: 02-06_typewriter_v2.c
	$(CC) $(CFLAGS) -o 02-06_typewriter_v2 02-06_typewriter_v2.c $(LFLAGS)

02-07_yourname: 02-07_yourname.c
	$(CC) $(CFLAGS) -o 02-07_yourname 02-07_yourname.c $(LFLAGS)

02-08_sushi: 02-08_sushi.c
	$(CC) $(CFLAGS) -o 02-08_sushi 02-08_sushi.c $(LFLAGS)


# ******************************************************************************
# Regras para a limpeza final (NÃO ALTERE!)
limpar:
	rm -f *~ a.out core graphics.ps

apagar: limpar
	rm -f *.o *.a $(PROGRAMAS)
