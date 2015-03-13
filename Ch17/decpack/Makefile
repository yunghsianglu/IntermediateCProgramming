GCC = gcc
CFLAGS = -g -Wall -Wshadow 
VALGRIND = valgrind --tool=memcheck --verbose --log-file

decpack: decpack.c decpack.h main.c
	$(GCC) $(CFLAGS) decpack.c main.c -o $@
	$(VALGRIND)=valgrindlog ./decpack

clean:
	/bin/rm -f *.o decpack *log

