#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#define HOOKE_CONST 1
#define X0 1
#define V0 1
void f(double x, double v, double* dx, double* dv);
void euler_step(double x0, double v0, int n_iter, double h, double* x_values, double* v_values);
void modified_euler_step(double x0, double v0, int n_iter, double h, double* x_values, double* v_values);
void rk4(double x0, double v0, int n_iter, double h, double* x_values, double* v_values);
void print_solution(double* x, double* v, int n_iter);
void runit(double step, int n_iter); 

int main(int argc, char* argv[]){
	/* usage: 
	 * main [step size] [stop time]
	 */

	assert(argc == 3); // need to specify step-size and stop time
	double step = atof(argv[1]);	// step size for ODE solution
	double stop_time = atof(argv[2]);	
	double n_iter = stop_time/step;
	runit(step, n_iter);
	return 0;
}

/* we use this function
 * because C allows runtime determination of size of stack-based array
 * when the size is an argument
 */
void runit(double step, int n_iter){
	double x[n_iter+1];
	double v[n_iter+1];
#ifdef EULER	
	euler_step(X0, V0, n_iter, step, x, v);	
#elif MODIFIED_EULER
	modified_euler_step(X0, V0, n_iter, step, x, v);
#elif RK4
	rk4(X0, V0, n_iter, step, x, v);
#endif
	print_solution(x, v, n_iter);
	return;
}

/* f = dy
 * compute derivative of system 
 * dv = f(x)
 * dx = v
 *
 * x: current value of x
 * v: current value of v
 * dx: pointer to variable to hold dx/dt
 * dv: pointer to variable to hold dv/dt 
 */
void f(double x, double v, double* dx, double* dv){
	*dx = v;
	*dv = -HOOKE_CONST*x;
	return;
}

/* perform euler stepping and record solution
 *
 * x0: initial condition for x
 * v0: initial condition for v
 * n_iter: number of iterations to run for
 * h: time step
 * x_values: array of size n_iter+1 to store x0 and n_iter x-values
 * v_values: array of size n_iter+1 to store v0 and n_iter v-values
 */
void euler_step(double x0, double v0, int n_iter, double h, double* x_values, double* v_values){
	double dx = 0, dv = 0;
	// initialise with initial condition
	x_values[0] = x0;
	v_values[0] = v0;

	for(int i = 0; i < n_iter; i++){
		// i is index of previous solution point
		f(x_values[i], v_values[i], &dx, &dv);
		// Euler step 
		x_values[i+1] = x_values[i] + h*dx;
		v_values[i+1] = v_values[i] + h*dv;
	}
	return;
}

/* perform modified Euler (Trapezoid/Heun's Method) stepping and record solution
 *
 * x0: initial condition for x
 * v0: initial condition for v
 * n_iter: number of iterations to run for
 * h: time step
 * x_values: array of size n_iter+1 to store x0 and n_iter x-values
 * v_values: array of size n_iter+1 to store v0 and n_iter v-values
 */
void modified_euler_step(double x0, double v0, int n_iter, double h, double* x_values, double* v_values){
	double dx = 0, dv = 0;
	double dx2 = 0, dv2 = 0; // "upstream" values of dx, dv
	// initialise with initial condition
	x_values[0] = x0;
	v_values[0] = v0;

	for(int i = 0; i < n_iter; i++){
		// i is index of previous solution point
		f(x_values[i], v_values[i], &dx, &dv);
		// this time we use the central difference method
		// so we compute the value at t+h/2 first
		x_values[i+1] = x_values[i] + h*dx;
		v_values[i+1] = v_values[i] + h*dv;
		// and calculate again the slope here
		f(x_values[i+1], v_values[i+1], &dx2, &dv2);
		// Euler step using approximate central difference derivative 
		x_values[i+1] = x_values[i] + 0.5*h*(dx + dx2);
		v_values[i+1] = v_values[i] + 0.5*h*(dv + dv2);
	}
	return;
}

/* Runge-Kutta 4th order 
 *
 */
void rk4(double x0, double v0, int n_iter, double h, double* x_values, double* v_values){
	double k1_x, k2_x, k3_x, k4_x;
	double k1_v, k2_v, k3_v, k4_v;
	// initialise with initial condition
	x_values[0] = x0;
	v_values[0] = v0;

	for(int i = 0; i < n_iter; i++){
		// i is index of previous solution point
		f(x_values[i], v_values[i], &k1_x, &k1_v);
		f(x_values[i] + (h/2)*k1_x, v_values[i] + (h/2)*k1_v, &k2_x, &k2_v);
		f(x_values[i] + (h/2)*k2_x, v_values[i] + (h/2)*k2_v, &k3_x, &k3_v);
		f(x_values[i] + h*k3_x, v_values[i] + h*k3_v, &k4_x, &k4_v);
		x_values[i+1] = x_values[i] + (h/6)*(k1_x + 2*k2_x + 2*k3_x + k4_x);
		v_values[i+1] = v_values[i] + (h/6)*(k1_v + 2*k2_v + 2*k3_v + k4_v);
	}
	return;
}

/* print solution in 2-column tab-separated format
 * x: x-values
 * v: v-values
 * n_iter: size of arrays 
 */
void print_solution(double* x, double* v, int n_iter){
	// header line
	printf("x\tv\n");
	for(int i = 0; i < n_iter; i++){
		printf("%lf\t%lf\n", x[i], v[i]);
	}
	return;
}
