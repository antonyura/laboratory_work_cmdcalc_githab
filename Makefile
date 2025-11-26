CompileAll : main.o calclib.o
	gcc main.o calclib.o -o cmdcalc.out
	make clean

main.o : main.c
	gcc -c main.c -o main.o

calclib.o : calclib.c
	gcc -c calclib.c -o calclib.o

clean : main.o calclib.o
	rm main.o
	rm calclib.o
