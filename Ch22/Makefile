TARGET = maze
GCC = gcc
CFLAGS = -g -Wall -Wshadow
CC = $(GCC) $(CFLAGS)
OBJS = main.o mazeread.o getout.o canmove.o
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

main.o: main.c maze.h
	$(CC) -c main.c

mazeread.o: mazeread.c maze.h
	$(CC) -c mazeread.c

canmove.o: canmove.c 
	$(CC) -c canmove.c

getout.o: getout.c 
	$(CC) -c getout.c

clean:
	rm -f $(OBJS) $(TARGET)
