#include <stdio.h>
#include <stdlib.h>

#define N_BITS 8 // use 16 bits (could use more)

void print_bin(int n){
	unsigned int n_uns = (unsigned int)n;
	for(int i = N_BITS-1; i >= 0; i--){
		// i counts which bit we want and we start with the HO bit
		printf("%d", (n_uns & (1 << i)) >> i);
	}
	printf("\n");
	return;
}

int main(int argc, char* argv[]){
	/** usage:
	 * print_bin <number>
	 **/

	if(argc != 2){
		printf("usage: print_bin <number>\n"); return 0;
	}
	int n = atoi(argv[1]);
	print_bin(n);
	return 0;
}
