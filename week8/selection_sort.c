#include <stdio.h>
#include <stdlib.h>

void swap(int A[], int i, int j){
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

void sel_sort(int A[], int n){
	for(int i = 0; i < n; i++){
		int max_idx = i;
		for(int j = i; j < n; j++){
			// seek max
			if(A[j] > A[max_idx]) max_idx = j;
		}
		swap(A, i, max_idx);
	}
}

int main(){

}
