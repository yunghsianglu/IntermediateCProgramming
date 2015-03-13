CFLAGS = -g -Wall -Wshadow 
GCC = gcc $(CFLAGS)
LIBS = -lm
SRCS = main.c bmpfile.c bmpinvert.c bmpcolor.c bmpedge.c bmpequalize.c bmphistogram.c bmpchecker.c bmpmix.c bmpgray.c
TARGET = image
OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --leak-check=full --tool=memcheck --verbose --log-file

$(TARGET): $(OBJS)
	$(GCC) $(OBJS) -o $@ $(LIBS)

.c.o: 
	$(GCC) -c $*.c 

test: $(TARGET)
	rm -f -r outputs/*
	rmdir outputs
	mkdir outputs
	./image inputs/eg5in.bmp gray outputs/eg5out.bmp

test2: $(TARGET)
	./image inputs/colorchecker.bmp mix outputs/colormix.bmp
	./image inputs/colorchecker.bmp red outputs/red.bmp
	./image inputs/colorchecker.bmp green outputs/green.bmp
	./image inputs/colorchecker.bmp blue outputs/blue.bmp
	./image inputs/colorchecker.bmp invert outputs/checkinvert.bmp
	./image inputs/eg1in.bmp checker outputs/eg1hist.bmp
	./image inputs/eg1in.bmp invert outputs/eg1out.bmp
	./image inputs/eg2in.bmp red outputs/eg2out.bmp
	./image inputs/eg4in.bmp green outputs/eg4out.bmp
	./image inputs/eg3in.bmp blue outputs/eg3out.bmp
	./image inputs/eg5in.bmp edge outputs/eg5out.bmp
	./image inputs/eg6in.bmp equalize outputs/eg6out.bmp
	./image inputs/eg7in.bmp equalize outputs/eg7out.bmp
	./image inputs/eg8in.bmp equalize outputs/eg8out.bmp
	./image inputs/eg9in.bmp equalize outputs/eg9out.bmp

clean:
	rm -f *.o a.out $(TARGET) *log outputs/*
