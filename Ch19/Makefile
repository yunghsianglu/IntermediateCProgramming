GCC = gcc
CFLAGS = -g -Wall -Wshadow
LIBS =
SOURCES = sparse.c main.c
TARGET = main
VALGRIND = valgrind --tool=memcheck --verbose --log-file
TEST0 = inputs/input0A inputs/input0B outputs/output0
TEST1 = inputs/input1A inputs/input1B outputs/output1

main: $(SOURCES)
	$(GCC) $(CFLAGS) $(SOURCES) -o $@
	./main $(TEST0)
	diff -w outputs/output0 expected/expected0
	./main $(TEST1)
	diff -w outputs/output1 expected/expected1
	$(VALGRIND)=outputs/valgrindlog0 ./main $(TEST0)
	$(VALGRIND)=outputs/valgrindlog1 ./main $(TEST1)

clean:
	/bin/rm -f main outputs/* 
