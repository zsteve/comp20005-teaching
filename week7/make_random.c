#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	int n = atoi(argv[1]);
	for(int i = 0; i < n; i++) printf("%d\n", rand() % 1000);
}
