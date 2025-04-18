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
	    04-01_charattrib \
	    04-02_changechar \
	    04-03_attrtest \
	    04-04_pi \
	    04-05_acslist \
	    04-06_acsstring \
	    04-07_abox \
	    04-08_chtypestring \
	    04-09_addchstr \
	    04-10_boxarray \
	    04-11_unicode \
	    04-12_ustring


# ******************************************************************************
# Regra padrão: compila todos os programas (NÃO ALTERE!)
all: $(PROGRAMAS)


# ******************************************************************************
# Regras individuais de compilação: crie as regras específicas de cada target:
04-01_charattrib: 04-01_charattrib.c
	$(CC) $(CFLAGS) -o 04-01_charattrib 04-01_charattrib.c $(LFLAGS)

04-02_changechar: 04-02_changechar.c
	$(CC) $(CFLAGS) -o 04-02_changechar 04-02_changechar.c $(LFLAGS)

04-03_attrtest: 04-03_attrtest.c
	$(CC) $(CFLAGS) -o 04-03_attrtest 04-03_attrtest.c $(LFLAGS)

04-04_pi: 04-04_pi.c
	$(CC) $(CFLAGS) -o 04-04_pi 04-04_pi.c $(LFLAGS)

04-05_acslist: 04-05_acslist.c
	$(CC) $(CFLAGS) -o 04-05_acslist 04-05_acslist.c $(LFLAGS)

04-06_acsstring: 04-06_acsstring.c
	$(CC) $(CFLAGS) -o 04-06_acsstring 04-06_acsstring.c $(LFLAGS)

04-07_abox: 04-07_abox.c
	$(CC) $(CFLAGS) -o 04-07_abox 04-07_abox.c $(LFLAGS)

04-08_chtypestring: 04-08_chtypestring.c
	$(CC) $(CFLAGS) -o 04-08_chtypestring 04-08_chtypestring.c $(LFLAGS)

04-09_addchstr: 04-09_addchstr.c
	$(CC) $(CFLAGS) -o 04-09_addchstr 04-09_addchstr.c $(LFLAGS)

04-10_boxarray: 04-10_boxarray.c
	$(CC) $(CFLAGS) -o 04-10_boxarray 04-10_boxarray.c $(LFLAGS)

04-11_unicode: 04-11_unicode.c
	$(CC) $(CFLAGS) -o 04-11_unicode 04-11_unicode.c $(LFLAGS)

04-12_ustring: 04-12_ustring.c
	$(CC) $(CFLAGS) -o 04-12_ustring 04-12_ustring.c $(LFLAGS)


# ******************************************************************************
# Regras para a limpeza final (NÃO ALTERE!)
limpar:
	rm -f *~ a.out core graphics.ps

apagar: limpar
	rm -f *.o *.a $(PROGRAMAS)
