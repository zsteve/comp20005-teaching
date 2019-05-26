#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	/* usage: gauss m n a11 a12 ... a1n ... // am1 ... amn
	 * and we expect a full rank system m * m+1
	 */
	
	double A[100][100]; // support up to 100x100 matrices
	int row_index[100];

	// we expect: 1 + 2 + m*n arguments
	if(argc <= 3){
		printf("Error: not enough arguments\n");
	}
	int m, n;
	m = atoi(argv[1]);
	n = atoi(argv[2]);

	printf("Input matrix expected dimensions: %d x %d\n", m, n);
	
	if(n != m+1){
		printf("Error: matrix is either overdetermined or underdetermined\n"); 
		return 0;
	}

	if(argc < (1 + 2 + m*n)){
		printf("Error: not enough arguments given matrix size\n");
		return 0;
	}	
	
	// fill rows first
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			A[i][j] = atof(argv[1 + 2 + i*n + j]);
			// printf("a%d%d = %lf\n", i, j, A[i][j]);
		}
	}
	for(int i = 0; i < m; i++) row_index[i] = i;
	
	for(int i = 0; i < m; i++){
		// find max and swap
		int max_piv = i;
		for(int j = i+1; j < m; j++){
			if(abs(A[row_index[j]][i]) > abs(A[row_index[max_piv]][i])){
				max_piv = j;
			}
		}
		int temp = row_index[i];
		row_index[i] = row_index[max_piv];
		row_index[max_piv] = temp;


		if(A[row_index[i]][i] == 0){
			printf("Error: null pivot, your system is less than full rank (underdetermined)\n"); break;
		}

		for(int j = i+1; j < m; j++){
			double mul = A[row_index[j]][i]/A[row_index[i]][i];
		       	for(int k = i; k < n; k++){
				A[row_index[j]][k] = A[row_index[j]][k] - mul*A[row_index[i]][k];
			}	
		}
	}

	// now backwards
	for(int i = m-1; i >= 0; i--){
		for(int k = n-1; k >= i; k--){
			A[row_index[i]][k] /= A[row_index[i]][i];
		}
		for(int j = i-1; j >= 0; j--){
			double mul = A[row_index[j]][i];
			for(int k = i; k < n; k++){
				A[row_index[j]][k] -= mul*A[row_index[i]][k];
			}
		}
	}
	printf("Final system\n");	
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			printf("%5.4lf ", A[row_index[i]][j]);
		}printf("\n");
	}
	printf("Solution (in terms of initial ordered system)\n");
	for(int i = 0; i < m; i++){
		printf("x_%d = %lf\n", i, A[row_index[i]][n-1]);
	}
	return 0;
}
