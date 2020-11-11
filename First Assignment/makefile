all: basicMath.o power.o main.o libmyMath.a mains maind libmyMath.so

basicMath.o: basicMath.c myMath.h
	gcc -g -Wall -fPIC -c basicMath.c -o basicMath.o

power.o: power.c myMath.h
	gcc -g -Wall -fPIC -c power.c -o power.o

main.o: main.c myMath.h
	gcc -g -Wall -c main.c -o main.o

mymaths: basicMath.o power.o
	ar -rcs libmyMath.a  basicMath.o power.o myMath.h

libmyMath.a: basicMath.o power.o
	make mymaths

libmyMath.so: basicMath.o power.o
	make mymathd

mains: libmyMath.a main.o
	gcc -g -Wall -o mains  main.o libmyMath.a -L.

maind: libmyMath.so main.o
	gcc -g -Wall main.o -L. ./libmyMath.so -o maind

mymathd: basicMath.o power.o
	gcc -g -Wall -shared basicMath.o power.o -o libmyMath.so
	export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH

clean:
	rm *.o *.out *.so *.a mains maind