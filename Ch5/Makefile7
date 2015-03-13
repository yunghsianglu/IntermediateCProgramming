GCC = gcc
CFLAGS = -g -Wall -Wshadow 
VALGRIND = valgrind --tool=memcheck --verbose --log-file


prog: aredistinct.o main.o
	$(GCC) $(CFLAGS) aredistinct.o main.o -o prog # no -c

aredistinct.o: aredistinct.c
	$(GCC) $(CFLAGS) -c aredistinct.c  

main.o: main.c
	$(GCC) $(CFLAGS) -c main.c

testall: test0 test1 test2 test3 test4

test0: prog
	./prog inputs/input0 > outputs/output0
	diff expected/expected0 outputs/output0
	$(VALGRIND)=log0 ./prog inputs/input0 > /dev/null

test1: prog
	./prog inputs/input1 > outputs/output1
	diff expected/expected1 outputs/output1
	$(VALGRIND)=log1 ./prog inputs/input0 > /dev/null

test2: prog
	./prog inputs/input2 > outputs/output2
	diff expected/expected2 outputs/output2
	$(VALGRIND)=log2 ./prog inputs/input0 > /dev/null

test3: prog
	./prog inputs/input3 > outputs/output3
	diff expected/expected3 outputs/output3
	$(VALGRIND)=log3 ./prog inputs/input0 > /dev/null

test4: prog
	./prog inputs/input4 > outputs/output4
	diff expected/expected4 outputs/output4
	$(VALGRIND)=log4 ./prog inputs/input0 > /dev/null

clean:
	/bin/rm -f *.o prog outputs/* log*


