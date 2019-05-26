#include <stdio.h>

  
int factorial(int n);

int main(int argc, char* argv[]){
    int n = 0;
    do{
            printf("Enter value of n: ");
    }while(scanf("%d", &n) != 1);
    printf("F(%d) = %d\n", n, factorial(n));
    return 0;
}

int factorial(int n){
	if(n == 0) return 1;
	return n*factorial(n-1);
}
