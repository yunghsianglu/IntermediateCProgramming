GCC = gcc
CFLAGS = -g -Wall -Wshadow
OBJS = mystring.o main.o
HDRS = mystring.h
VAL = valgrind --tool=memcheck --leak-check=full 
VAL += --verbose --log-file=

mystring: $(OBJS) $(HDRS)
	$(GCC) $(CFLAGS) $(OBJS) -o $@

.c.o: 
	$(GCC) $(CFLAGS) -c $*.c

clean:
	rm -f mystring $(OBJS) out_* log*

testall: test0 test1 test2

test0: mystring
	$(VAL)log0 ./mystring strlen input out_len
	diff -q out_len expected_strlen

test1: mystring
	$(VAL)log1 ./mystring countchar input output_countchar
	diff -q output_countchar expected_countchar

test2: mystring
	$(VAL)log2 ./mystring strupper input out_upper
	diff -q out_upper expected_strupper
