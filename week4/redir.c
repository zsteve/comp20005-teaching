#include <stdio.h>

int main( int argc, char* argv[]){
	int n = 0;
	while(scanf("%d", &n) > 0){
		printf("Input was: %d;\t%d^2 = %d\n", n, n, n*n);
	}
	return 0;
}
