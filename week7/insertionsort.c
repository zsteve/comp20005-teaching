#include <stdio.h>

#define ARR_SIZE 100000

void swap(int[], int, int);
void insertion_sort(int[], int);

int main(int argc, char* argv[]){
        int A[ARR_SIZE];
        int n = 0;
        while(scanf("%d", A+n) == 1 && n < ARR_SIZE) n++;
        printf("%d\n", n);
        insertion_sort(A, n);
        for(int i = 0; i < n; i++) printf("%d ", A[i]);
        printf("\n");
        return 0;
}

void swap(int A[], int i, int j){
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
        return;
}

void insertion_sort(int A[], int n){
        /*
         * in-place insertion sort to put A[] into
         * ascending order
         */
	for(int i = 1; i < n; i++){
		int j = i;
		while(j > 0 && A[j-1] > A[j]){
			swap(A, j, j-1);
			j--;
		}
	}	
        return;
}
