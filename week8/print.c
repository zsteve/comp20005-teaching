#include <stdio.h>

void myprint(char s[]){
	while(*s){
		putchar((int)*(s++));
	}
}

int main(int argc, char* argv[]){
	char string1[5] = "frank";
	char string2[5] = "frank";	
	char a = 0x7; 
	myprint(string1);
	return 0;
}
