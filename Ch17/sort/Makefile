CFLAGS = -g -Wall -Wshadow
GCC = gcc $(CFLAGS)
SRCS = person.c main.c
OBJS = $(SRCS:%.c=%.o)
TEST = ./main database output1 output2
VALGRIND = valgrind --tool=memcheck --leak-check=full --verbose --log-file=

main: $(OBJS) 
	$(GCC) $(OBJS) -o main

test: main
	$(TEST)
	diff output1 sortbyname
	diff output2 sortbyage
	$(VALGRIND)logfile $(TEST)

memory: main
	valgrind --leak-check=yes --verbose $(TEST)

.c.o: 
	$(GCC) $(CFLAGS) -c $*.c 

clean:
	rm -f *.o a.out main output* logfile

headers:
	makedepend $(SRCS) 

# DO NOT DELETE

