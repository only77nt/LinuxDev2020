bin_PROGRAMS=main
main_SOURCES=main.c

@DX_RULES@

LOCALMSG = ru/LC_MESSAGES

all: mo localtest
	
main.pot: main.c
	xgettext $< -c -k_ -o $@	

initru:
	msginit -i main.pot -o main.po -l ru
	
mo:
	mkdir $(LOCALMSG) -p
	msgfmt main.po -o l10n.mo
	mv l10n.mo $(LOCALMSG)/
	
merge:
	msgmerge -U main.po main.pot
	
maintest:
	cc main.c -o main
	./main.out
	
localtest: 
	cc main.c -o main
	PO_LOCAL=1 ./main
	
test:
	gcc main.c -o main
	./main
	PO_LOCAL=1 ./main

gitclean:
	git clean -fd
	rm main.o
	rm a.out
