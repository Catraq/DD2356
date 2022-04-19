#include <stdio.h>
#include <stdlib.h>

#include <omp.h>

#define N 10000000

int main(int argcs, char *argv[])
{
	double sum = 0.0;
	double *array = malloc(sizeof(double) * N);

	for(size_t i = 0; i < N; i++)
		array[i] = rand()/(double)(RAND_MAX);


	double start_time = omp_get_wtime();
#pragma omp parallel for
	for(size_t i = 0; i < N; i++)
	{
#pragma omp critical
		sum += array[i];	
	}


	double delta = omp_get_wtime() - start_time;

	printf("delta=%f, sum=%f \n", delta, sum);
	
	return 0;
}


