GCC = gcc
CFLAGS = -g -Wall -Wshadow
LIBS = -lpthread
VALGRIND = valgrind --tool=memcheck 
VALGRIND += --verbose --log-file
COMMONOBJS = countint.o isvalid.o subsetequal.o main.o

thread1: thread1.c
	$(GCC) $(CFLAGS) thread1.c -o thread1 $(LIBS)
	$(VALGRIND)=log1 ./thread1 

sequential: sequential.c $(COMMONOBJS)
	$(GCC) $(CFLAGS) sequential.c $(COMMONOBJS) -o sequential

parallel: parallel.c $(COMMONOBJS)
	$(GCC) $(CFLAGS) parallel.c $(COMMONOBJS) -o parallel $(LIBS)

sync: sync.c
	$(GCC) $(CFLAGS) sync.c -o sync $(LIBS)
	./sync

outsync: outsync.c
	$(GCC) $(CFLAGS) outsync.c -o outsync $(LIBS)
	./outsync

testall: parallel sequential
	/bin/rm -f -r outputs
	mkdir outputs
	./parallel inputs/validyes1 > outputs/paloutvy1
	./parallel inputs/validyes2 > outputs/paloutvy2
	./parallel inputs/validyes3 > outputs/paloutvy3
	./parallel inputs/validyes4 > outputs/paloutvy4
	./parallel inputs/validyes5 > outputs/paloutvy5
	# ./parallel inputs/validyes6 > outputs/paloutvy6
	./parallel inputs/validno1  > outputs/paloutvn1
	./parallel inputs/validno2  > outputs/paloutvn2
	./parallel inputs/validno3  > outputs/paloutvn3
	./parallel inputs/validno4  > outputs/paloutvn4
	./parallel inputs/validno5  > outputs/paloutvn5
	# ./parallel inputs/validno6  > outputs/paloutvn6
	./parallel inputs/invalid1  > outputs/paloutiv1
	./parallel inputs/invalid2  > outputs/paloutiv2
	./parallel inputs/invalid3  > outputs/paloutiv3
	./parallel inputs/invalid4  > outputs/paloutiv4
	./parallel inputs/invalid5  > outputs/paloutiv5
	# ./parallel inputs/invalid6  > outputs/paloutiv6
	./sequential inputs/validyes1 > outputs/seqoutvy1
	./sequential inputs/validyes2 > outputs/seqoutvy2
	./sequential inputs/validyes3 > outputs/seqoutvy3
	./sequential inputs/validyes4 > outputs/seqoutvy4
	./sequential inputs/validyes5 > outputs/seqoutvy5
	# ./sequential inputs/validyes6 > outputs/seqoutvy6
	./sequential inputs/validno1  > outputs/seqoutvn1
	./sequential inputs/validno2  > outputs/seqoutvn2
	./sequential inputs/validno3  > outputs/seqoutvn3
	./sequential inputs/validno4  > outputs/seqoutvn4
	./sequential inputs/validno5  > outputs/seqoutvn5
	# ./sequential inputs/validno6  > outputs/seqoutvn6
	./sequential inputs/invalid1  > outputs/seqoutiv1
	./sequential inputs/invalid2  > outputs/seqoutiv2
	./sequential inputs/invalid3  > outputs/seqoutiv3
	./sequential inputs/invalid4  > outputs/seqoutiv4
	./sequential inputs/invalid5  > outputs/seqoutiv5
	# ./sequential inputs/invalid6  > outputs/seqoutiv6

testgen: testgen.c
	$(GCC) $(CFLAGS) testgen.c -o testgen
	/bin/rm -f -r inputs
	mkdir inputs
	./testgen  5 1 1 > inputs/validyes1
	./testgen 10 1 1 > inputs/validyes2
	./testgen 15 1 1 > inputs/validyes3
	./testgen 20 1 1 > inputs/validyes4
	./testgen 25 1 1 > inputs/validyes5
	./testgen 30 1 1 > inputs/validyes6
	./testgen  5 1 0 > inputs/validno1
	./testgen 10 1 0 > inputs/validno2
	./testgen 15 1 0 > inputs/validno3
	./testgen 20 1 0 > inputs/validno4
	./testgen 25 1 0 > inputs/validno5
	./testgen 30 1 0 > inputs/validno6
	./testgen  5 0 0 > inputs/invalid1
	./testgen 10 0 0 > inputs/invalid2
	./testgen 15 0 0 > inputs/invalid3
	./testgen 20 0 0 > inputs/invalid4
	./testgen 25 0 0 > inputs/invalid5
	./testgen 30 0 0 > inputs/invalid6

.c.o: 
	$(GCC) $(CFLAGS) -c $*.c 

clean:
	/bin/rm -f thread1 seqout* parallel  
	/bin/rm -f sequential log* testgen *.o
	/bin/rm -f -r outputs sync outsync




