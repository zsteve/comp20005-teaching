#include <stdio.h>

#define RED 1
#define GREEN 2
#define BLUE 3

typedef struct { 
	double weight; // in g
	int color;
	double price; // in AUD
}fruit;

fruit half_price(fruit a){
	a.price = a.price/2;
	return a;
}

int main(int argc, char* argv[]){
	fruit banana = {.weight = 50.0, .color = GREEN, .price = 2.20};
	fruit cheap_banana = half_price(banana);
	printf("banana.price = %lf\n", banana.price);
	printf("cheap_banana.price = %lf\n", cheap_banana.price);	
	return 0;
}
