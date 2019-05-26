#include <stdio.h>
#include <stdlib.h>

int main(){
	int n = 0;
	char c = 0;
	while((c = getchar()) != EOF){
		// we input from HO to LO bit
		int bit = 0;
		if(c == '1'){
			bit = 1;
		}else if(c == '0'){
			bit = 0;
		}else{
			break;	
		}
		n |= bit;
		n <<= 1;
	}
	n >>= 1;
	printf("0x%.4x\n", n);
	return 0;
}
