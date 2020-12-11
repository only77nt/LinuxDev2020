bin_PROGRAMS=main
main_SOURCES=main.c

LOCALMSG = ${prefix}/share/ru/LC_MESSAGES
NEWLOCAL = /ru/LC_MESSAGES

all: prefix

prefix: 
	sudo make install
	sudo mkdir $(LOCALMSG) -p
	msgfmt main.po -o l10n.mo
	sudo mv l10n.mo $(LOCALMSG)/
	${prefix}/bin/main ${prefix}/share/ru/
	
realinstall: 
	sudo make install DESTDIR=/home/korotkovbs/tmp/myprog
	sudo mkdir $(DESTDIR)$(LOCALMSG) -p
	msgfmt main.po -o l10n.mo
	sudo mv l10n.mo $(DESTDIR)$(LOCALMSG)/
	$(DESTDIR)${prefix}/bin/main $(DESTDIR)${prefix}/share/ru/
	
main.pot: main.c
	xgettext $< -c -k_ -o $@	

initru:
	msginit -i main.pot -o main.po -l ru
	
mo:
	sudo mkdir $(NEWLOCAL) -p
	msgfmt main.po -o l10n.mo
	sudo mv l10n.mo $(NEWLOCAL)/
	
merge:
	msgmerge -U main.po main.pot

gitclean:
	git clean -fd
