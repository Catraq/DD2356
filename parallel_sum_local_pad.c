#include <stdio.h>
#include <stdlib.h>

#include <omp.h>

#define N 10000000

#define MAX_THREADS 32
struct local_sum 
{
	double sum;
	char pad[128];
};

int main(int argcs, char *argv[])
{
	double sum = 0.0;
	double *array = malloc(sizeof(double) * N);

	for(size_t i = 0; i < N; i++)
		array[i] = rand()/(double)(RAND_MAX);	
		
		
	struct local_sum ls[MAX_THREADS];
	
	for(size_t i = 0; i < MAX_THREADS; i++)
	{
		ls[i].sum = 0;
	}
	
	
	double start_time = omp_get_wtime();	
	
	#pragma omp parallel shared(ls)
	{
		int th_id = omp_get_thread_num();

		#pragma omp for 
		for(int k = 0; k < N; k++)
		{
			ls[th_id].sum = ls[th_id].sum + array[k];	
		}
	}

	
	for(size_t i = 0; i < MAX_THREADS; i++)
	{
		sum += ls[i].sum;
	}
	
	double delta = omp_get_wtime() - start_time;

	printf("delta=%f, sum=%f \n", delta, sum);
	
	return 0;
}


