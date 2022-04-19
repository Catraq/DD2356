#include <stdio.h>
#include <stdlib.h>

#include <omp.h>

#define N 10000000

#define MAX_THREADS 32

int main(int argcs, char *argv[])
{
	double sum = 0.0;
	double *array = malloc(sizeof(double) * N);

	for(size_t i = 0; i < N; i++)
		array[i] = rand()/(double)(RAND_MAX);	
		
		
	double local_sum[MAX_THREADS];
	
	for(size_t i = 0; i < MAX_THREADS; i++)
	{
		local_sum[i] = 0;
	}
	
	
	double start_time = omp_get_wtime();	
	
	#pragma omp parallel shared(local_sum)
	{
		int th_id = omp_get_thread_num();

		#pragma omp for 
		for(int k = 0; k < N; k++)
		{
			local_sum[th_id] = local_sum[th_id] + array[k];	
		}
	}

	
	for(size_t i = 0; i < MAX_THREADS; i++)
	{
		sum += local_sum[i];
	}
	
	double delta = omp_get_wtime() - start_time;

	printf("delta=%f, sum=%f \n", delta, sum);
	
	return 0;
}


