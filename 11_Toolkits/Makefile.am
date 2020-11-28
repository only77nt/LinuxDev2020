bin_PROGRAMS = main
CFLAGS += $(GLIB_CFLAGS) -Wall
LIBS += $(GLIB_LIBS)

run: 
	./main

test: test.txt
	./main $^

gitclean:
	git clean -fd
	main.o
