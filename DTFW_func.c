
#define MAX_THREADS 32 

struct DTF_thread_storage
{
	double Xr;
	double Xi; 	
	char pad[128];
};


int DFT(int idft, double *xr, double *xi, double *Xr_o, double *Xi_o, int N) {


	#pragma omp parallel for 
	for (int k = 0; k < N; k++) {

		struct DTF_thread_storage storage[MAX_THREADS] = {};
		for (int n = 0; n < N; n++) {
			
			int thread_id = omp_get_thread_num();
			//Storage at index k 
			storage[thread_id].Xr += xr[n] * cos(n * k * PI2 / N) + idft * xi[n] * sin(n * k * PI2 / N);
			storage[thread_id].Xi += -idft * xr[n] * sin(n * k * PI2 / N) + xi[n] * cos(n * k * PI2 / N);
		}
		for(int i = 0; i < MAX_THREADS; i++)
		{
			Xr_o[k] += storage[i].Xr;
			Xi_o[k] += storage[i].Xi;
		}
	}

	// normalize if you are doing IDFT
	if (idft == -1) {
		for (int n = 0; n < N; n++) {
			Xr_o[n] /= N;
			Xi_o[n] /= N;
		}
	}
	return 1;
}

