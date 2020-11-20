bin_PROGRAMS=main
main_SOURCES=main.c

@DX_RULES@

LOCALMSG = ru/LC_MESSAGES

all: mo doxygen 
	
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
	
doxygen:
	make doxygen-doc
	
doc_server:
	python3 -m http.server -d doxygen-doc/html/ 8500
	
help:
	cc main.c -o main
	help2man ./main > guess.1
	less guess.1
	
test:
	cc main.c -o main
	./main
	
test_local:
	cc main.c -o main
	PO_LOCAL=1 ./main
	
test_help:
	cc main.c -o main
	./main --help
	./main --version
	
test_help_local:
	cc main.c -o main
	PO_LOCAL=1 ./main --help
	./main --version
	
test_roman:
	cc main.c -o main
	./main -r

gitclean:
	git clean -fd
	rm main.o
