#include <stdio.h>

int fib(int n); // <-- this is a function PROTOTYPE
    
int main(int argc, char* argv[]){
    int n = 0;
    do{
            printf("Enter value of n: ");
    }while(scanf("%d", &n) != 1);
    printf("F(%d) = %d\n", n, fib(n));
    return 0;
}

int fib(int n){
	printf("hello\n");
	if( n == 1 || n == 2 ){
		return 1;
	}
	return fib(n-1) + fib(n-2);
}
