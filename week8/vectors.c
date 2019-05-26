#include <stdio.h>
#include <stdlib.h>

typedef struct{
	double x, y, z;
} vec_t;

double dotp(vec_t a, vec_t b){
	return a.x*b.x + a.y*b.y + a.z*b.z;
}

vec_t crossp(vec_t a, vec_t b){
	return (vec_t){.x = (a.y*b.z-a.z*b.y),
			.y = -(a.x*b.z-a.z*b.x),
			.z = a.x*b.y-a.y*b.x };
}

void print_vec(vec_t a){
	printf("[%lf, %lf, %lf]", a.x, a.y, a.z);
}

int main(int argc, char* argv[]){
	vec_t a = {.x = 1, .y = 2, .z= 3 };
	vec_t b = {.x = 3, .y = 2, .z = 1};
	printf("a.b = %lf\n", dotp(a, b));
	printf("a*b = "); print_vec(crossp(a, b)); printf("\n");
	return 0;
}
