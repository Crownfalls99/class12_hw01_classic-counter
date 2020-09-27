all : classic-counter

classic-counter : classic-counter.o analysis.o main.o
	gcc -O2 -o classic-counter classic-counter.o analysis.o main.o -l pthread

classic-counter.o : classic-counter.c classic-counter.h
	gcc -O2 -c -o classic-counter.o classic-counter.c -l pthread

analysis.o : analysis.c classic-counter.h
	gcc -O2 -c -o analysis.o analysis.c -l pthread

main.o : main.c classic-counter.h
	gcc -O2 -c -o main.o main.c -l pthread

clean:
	rm -f classic-counter *.o



