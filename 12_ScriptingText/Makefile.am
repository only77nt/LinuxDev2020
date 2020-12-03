bin_PROGRAMS = prog

GENERATES = prog prog-a prog-so
LIBS = liboutput_static.a liboutput.so
TRASH = *.o *~ o.* *.txt

all: build static_lib dinamic_lib prog-a prog-so

build: const.o fun.o prog.o

test: prog static_lib dinamic_lib prog-a prog-so test0 test1 test3 clean_all
	echo "Test complite!"

fun.o:	outlib.h

static_lib: fun.o const.o
	ar -rcs liboutput_static.a $^
	
dinamic_lib: prog.o fun.o const.o
	make clean CFLAGS=-fPIC $^
	cc -shared fun.o const.o -o liboutput.so

prog-a: prog.o liboutput_static.a
	cc -L. $< -loutput_static -o $@

prog-so: prog.o liboutput.so
	cc -L. $< -loutput -o $@

test0:
	./prog > file.txt
	./prog-a > file-a.txt
	LD_LIBRARY_PATH=`pwd` ./prog-so > file-so.txt
	make compare
	
test1:
	./prog Hello > file.txt
	./prog-a Hello > file-a.txt
	LD_LIBRARY_PATH=`pwd` ./prog-so Hello > file-so.txt
	make compare

test3:
	./prog Hello make file > file.txt
	./prog-a Hello make file > file-a.txt
	LD_LIBRARY_PATH=`pwd` ./prog-so Hello make file > file-so.txt
	make compare

compare: file.txt file-a.txt file-so.txt
	cmp file.txt file-a.txt
	cmp file.txt file-so.txt
	cmp file-a.txt file-so.txt
	rm -f *.txt

clean:
	rm -f $(TRASH)

distclean:
	rm -rf $(GENERATES)
	
libclean: 
	rm -f $(LIBS)
	
clean_all: clean distclean libclean
