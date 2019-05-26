#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N_ITER 100

double f(double r, double x){
	return 0.5*(x + r/x);
}

int main(int argc, char* argv[]){
	double r = 0; double guess = 0;
	if(argc != 3){ exit(EXIT_FAILURE); }
	r = (double)atof(argv[1]);
	guess = (double)atof(argv[2]);
	printf("r = %lf, guess = %lf\n", r, guess);
	for(int i = 0; i < N_ITER; i++){
		guess = f(r, guess);
		printf("Iteration %d: guess = %.8lf, actual = %.8lf, error = %.8lf\n", 
				i+1, 
				guess,
				sqrt(r),
				guess - sqrt(r));
	}
	return 0;	
}
