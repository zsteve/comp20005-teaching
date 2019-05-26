#include <stdio.h>

int main( int argc, char *argv[]){
	int n = 0; // which F_n do we want?
       	do{
		printf("Enter the value of n: ");
	}while(scanf("%d", &n) != 1);

	int f_prev = 1; int f_prev_prev = 1; int f = -1;
	if( n == 0 || n == 1 ){
		f = 1;	
	}else{
		for(int i = 1; i < n; i++){
			f = f_prev + f_prev_prev;
			f_prev_prev = f_prev;
			f_prev = f;
		}	
	}
	printf("F_%d = %d\n", n, f);
	return 0;
}
