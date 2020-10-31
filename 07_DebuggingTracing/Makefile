GENERATES = wrapper.so testfile testFIXtest
TRASH = *.o *~ o.*
#MAKEFLAGS += --silent

all: lib testing

lib: wrapper.c
	cc -shared -fPIC wrapper.c -ldl -o wrapper.so
	
testing:
	touch testfile
	touch testFIXtest
	rm testfile
	rm testFIXtest
	@if [ -f testfile ]; then echo "testfile exists"; else echo "testfile does't exists"; fi;
	@if [ -f testFIXtest ]; then echo "testFIXtest exists"; else echo "testFIXtest does't exists"; fi;
	touch testfile
	touch testFIXtest
	LD_PRELOAD=`pwd`/wrapper.so rm testfile
	@if [ -f testfile ]; then echo "testfile exists"; else echo "testfile does't exists"; fi;
	LD_PRELOAD=`pwd`/wrapper.so rm testFIXtest
	@if [ -f testFIXtest ]; then echo "testFIXtest exists"; else echo "testFIXtest does't exists"; fi;

clean:
	rm -f $(TRASH)
	
distclean:
	rm -rf $(GENERATES)
	
allclean: clean distclean
