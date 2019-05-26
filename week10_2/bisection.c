#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function to find the root of 
// x: value at which to evaluate
// return: evaluated value
double f(double x){
	return x*x-x-1;
}

// return sign of x
// 1 if positive, 0 if negative or zero
int sign(double x){
	if(x > 0){
		return 1;
	}else{
		return 0;
	}
	return 0;
}

#define DIFF_SIGN(a, b) sign(a) != sign(b)

#define TOL 1e-5

// find root of f by bisection
// [lo, hi]: range in which to search
// tol: tolerance
// successful: pointer to int (contains the result, 0 if fail, 1 if success)
// return: location of root
double bisection(double lo, double hi, double tol, int* successful){
	while(hi - lo > tol){
		double mid = (lo + hi)/2;
		if(DIFF_SIGN(f(lo), f(mid))){
			// pick lower subinterval
			hi = mid;
		}else if(DIFF_SIGN(f(mid), f(hi))){
			// pick upper subinterval
			lo = mid;
		}else{
			// signs the same for both subintervals
			// failed to find root
			*successful = 0;
			return 0;
		}
		printf("lo = %lf, hi = %lf\n", lo, hi);
	}	
	*successful = 1; // root finding was successful
	return (lo + hi)/2; // return new midpoint
}

int main(int argc, char* argv[]){
	double lo, hi; // declare some variables <-- useless comment
	lo = atof(argv[1]); // first argument is lo
	hi = atof(argv[2]); // second argument is hi

	int flag = 0;	
	double root = bisection(lo, hi, TOL, &flag);
	return 0;
}
