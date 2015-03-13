CFLAGS = -g -Wall -Wshadow
GCC = gcc $(CFLAGS)
SRCS = main.c encode.c freq.c tree.c list.c utility.c
OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --leak-check=full --tool=memcheck --verbose --log-file

testall: code test1 test2 test3

code: $(OBJS) 
	$(GCC) $(OBJS) -o code

test1: code
	./code e input1 compress1
	$(VALGRIND)=logenc1 ./code e input1 compress1
	./code d compress1 output1
	$(VALGRIND)=logdec1 ./code d compress1 output1
	echo # add a blank line
	diff input1 output1

test2: code
	./code e input2 compress2
	$(VALGRIND)=logenc2 ./code e input2 compress2
	./code d compress2 output2
	$(VALGRIND)=logdec2 ./code d compress2 output2
	echo # add a blank line
	diff input2 output2

test3: code
	./code e input3 compress3
	$(VALGRIND)=logenc3 ./code e input3 compress3
	./code d compress3 output3
	$(VALGRIND)=logdec3 ./code d compress3 output3
	echo # add a blank line
	diff input3 output3

.c.o: 
	$(GCC) $(CFLAGS) -c $*.c 

clean:
	rm -f *.o a.out code log*



