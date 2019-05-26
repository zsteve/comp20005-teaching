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
    // compute nth fibonacci number
    int fib_1 = 1, fib_2= 1;
    int f = 0;
    if( n == 1 || n == 2 ){
            f = 1;
    }else{
            for(int i = 2; i < n; i++){
                    f = fib_1 + fib_2;
                    fib_1 = fib_2;
                    fib_2 = f;
            }
    }
    return f;
}
