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
	    05-01_screensize \
	    05-02_stdscrsize \
	    05-03_corners \
	    05-04_ctitle \
	    05-05_whereami


# ******************************************************************************
# Regra padrão: compila todos os programas (NÃO ALTERE!)
all: $(PROGRAMAS)


# ******************************************************************************
# Regras individuais de compilação: crie as regras específicas de cada target:
05-01_screensize: 05-01_screensize.c
	$(CC) $(CFLAGS) -o 05-01_screensize 05-01_screensize.c $(LFLAGS)

05-02_stdscrsize: 05-02_stdscrsize.c
	$(CC) $(CFLAGS) -o 05-02_stdscrsize 05-02_stdscrsize.c $(LFLAGS)

05-03_corners: 05-03_corners.c
	$(CC) $(CFLAGS) -o 05-03_corners 05-03_corners.c $(LFLAGS)

05-04_ctitle: 05-04_ctitle.c
	$(CC) $(CFLAGS) -o 05-04_ctitle 05-04_ctitle.c $(LFLAGS)

05-05_whereami: 05-05_whereami.c
	$(CC) $(CFLAGS) -o 05-05_whereami 05-05_whereami.c $(LFLAGS)


# ******************************************************************************
# Regras para a limpeza final (NÃO ALTERE!)
limpar:
	rm -f *~ a.out core graphics.ps

apagar: limpar
	rm -f *.o *.a $(PROGRAMAS)
