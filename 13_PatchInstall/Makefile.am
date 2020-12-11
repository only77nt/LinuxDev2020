bin_PROGRAMS=main
main_SOURCES=main.c

LOCALMSG = ${prefix}/share/ru/LC_MESSAGES

all: prefix

prefix: 
	sudo make install
	sudo mkdir $(LOCALMSG) -p
	msgfmt main.po -o l10n.mo
	sudo mv l10n.mo $(LOCALMSG)/
	${prefix}/bin/main ${prefix}/share/ru/
	
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

gitclean:
	git clean -fd
