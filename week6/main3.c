#include <stdio.h>

int main(){

int my_number = 0;
printf("my_number = %d\n", my_number);
int* p = &my_number;
char* q = (char*)p;
*q = 'a';
printf("my_number = %d\n", my_number);
	return 0;  
}
