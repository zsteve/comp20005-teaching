#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define DIFF_SIGN(a, b) sign(a) != sign(b)
#define TOL 1e-5

double f(double k);
int sign(double x);
double bisection(double lo, double hi, double tol, int* result);

int main(int argc, char* argv[]){
	double lo, hi;
	int flag = 0;
	lo = atof(argv[1]);
	hi = atof(argv[2]);
	bisection(lo, hi, TOL, &flag);
	return 0;
}

/* the function we want to find roots of
 * x: value at which to evaluate
 * returns: f(x)
 */
double f(double x){
	return x*x - x - 1; 
}

/* get sign of x
 * x: a double
 * returns: +1 if x positive, -1 if x negative, else 0
 */
int sign(double x){
	if(x > 0){
		return 1;
	}else if(x < 0){
		return -1;
	}
	return 0;
}

/* find a root by bisection method
 * lo: lower bound
 * hi: upper bound
 * tol: tolerance
 * result: write 1 for success, 0 for failure
 * returns: value of root, if successful.
 */
double bisection(double lo, double hi,double tol, int* result){	
	assert(lo < hi);
	while(hi - lo > tol){ // exit once interval < tol
		printf("lo = %lf, hi = %lf\n", lo, hi);
		double mid = (lo + hi)/2;
		if(DIFF_SIGN(f(lo), f(mid))){ 
			hi = mid;	// pick lower half interval
		}else if(DIFF_SIGN(f(mid), f(hi))){
			lo = mid;	// pick upper half interval
		}else{
			*result = 0;	// failure, return 0
			return 0;
		}
	}
	*result = 1; // success
	return (lo + hi)/2; // return new midpoint

}
