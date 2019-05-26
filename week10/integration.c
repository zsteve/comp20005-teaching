#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

double f(double x){
	return x*exp(-x);
}

double F(double x){
	return -exp(-x)*(x+1);
}

double trapezoid(double lo, double hi, double step){
	double x = lo + step;
	double sum = 0;
	assert(lo < hi);
	while(x <= hi){
		sum += 0.5*step*(f(x-step) + f(x));
		x+=step;
	}
	x-=step;
	step = hi - x;
	sum += 0.5*step*(f(x) + f(x+step));
	return sum;
}

double simpson(double lo, double hi, double step){
	double x = lo + step;
	double sum = 0;
	assert(lo < hi);
	while(x <= hi){
		sum += (step/6)*(f(x-step)+4*f(x - 0.5*step) + f(x));
		x+=step;
	}// some nitty gritty fixup stuff
	x-=step;
	step = hi - x;
	sum += (step/6)*(f(x) + 4*f(x + 0.5*step) + f(x + step));
	return sum;
}

int main(){
	double lo = 0; double hi = 1;
	double step = 0.001;
	printf("Trapezoid: \t \t area = %lf\n", trapezoid(lo, hi, step));	
	printf("Simpson  : \t \t area = %lf\n", simpson(lo, hi, step));
	printf("Exact    : \t \t area = %lf\n", F(hi)-F(lo));
}
