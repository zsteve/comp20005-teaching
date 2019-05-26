#include <stdio.h>
#include <stdlib.h>

double f(double x){
	return x*x-x-1;
}

int sign(double x){
	if(x > 0){
		return 1;
	}else if(x < 0){
		return -1;
	}
	return 0;
}

#define SIGN_DIFF(a, b) sign(a) != sign(b)
#define TOL 1e-5

int main(int argc, char* argv[]){
	// usage: main lo hi 
	if(argc != 3) return 0;
	double lo = atof(argv[1]);
	double hi = atof(argv[2]);	
	if(hi < lo){
		printf("Error: hi < lo\n"); return 0;
	}
	while(hi - lo > TOL){
		double mid = (hi + lo)/2;
		if(SIGN_DIFF(f(lo), f(mid))){
			hi = mid;
		}else if(SIGN_DIFF(f(mid), f(hi))){
			lo = mid;
		}else{
			printf("Error: no sign change\n"); return 0;
		}
		printf("lo = %lf, hi = %lf\n", lo, hi);
	}
	printf("Bisection found root at: %lf\n", (hi + lo)/2);
	return 0;
}
