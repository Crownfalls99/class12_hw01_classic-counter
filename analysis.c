# include "classic-counter.h"

void ellapsedTime (TIMEV* diffTime, TIMEV* startTime, TIMEV* endTime) {
	if (endTime->tv_usec < startTime->tv_usec) {
		endTime->tv_sec--;
		endTime->tv_usec += 1000000;
	}
	diffTime->tv_sec = endTime->tv_sec - startTime->tv_sec;
	diffTime->tv_usec = endTime->tv_usec - startTime->tv_usec;
}

void printTime(TIMEV time) {
	printf("%ld.%06ld sec\n", time.tv_sec, time.tv_usec);
}

void* mythread(void* arg) {
	int i;

	for(i = 0; i < ITR; i++)
		increment((counter_t*)arg);
	return NULL;
}

void Nthreads(int n) {
	pthread_t p[n];
	counter_t c;
	TIMEV start, end, diff;
	int i;

	init(&c);
	gettimeofday(&start, NULL);

	for(i = 0; i < n ; i++) 
		Pthread_create(&p[i], NULL, mythread, (void*) &c );

	for(i = 0; i < n; i++)
		Pthread_join(p[i], NULL);

	gettimeofday(&end, NULL);
	ellapsedTime(&diff, &start, &end);

	printf("For %d threads, total ellapsed time : ", n);
        printTime(diff);
        printf("Value : %d\n", get(&c));
}


