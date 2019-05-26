#include <stdio.h>

int main(){
#define PRINT_SIZE(TYPE, TYPENAME) printf("Size of "TYPENAME" is: %d\n", sizeof(TYPE))
      
PRINT_SIZE(char, "char");
PRINT_SIZE(int, "int");
PRINT_SIZE(long int, "long int");
PRINT_SIZE(double, "double");
PRINT_SIZE(float, "float");return 0;
}
