# include "classic-counter.h"

int main(int argc, char* argv[])
{
	int n;

	for(n = 1;n <= NUM_THREADS; n++)
		Nthreads(n);

	return 0;
}


