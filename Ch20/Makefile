CFLAGS = -g -Wall -Wshadow
GCC = gcc $(CFLAGS)
SRCS = treemain.c treesearch.c treedestroy.c treeinsert.c 
SRCS += treeprint.c treedelete.c 
OBJS = $(SRCS:%.c=%.o)

tree: $(OBJS) 
	$(GCC) $(OBJS) -o tree

memory: tree
	valgrind --leak-check=yes --verbose ./tree 10

.c.o: 
	$(GCC) $(CFLAGS) -c $*.c 

clean:
	rm -f *.o a.out tree


