#include <stdio.h>

#define RED 1
#define GREEN 2
#define BLUE 3
#define YELLOW 4
typedef struct{
	double price; // AUD
	int color;	// see #defines
	double mass;	// g


}fruit;

fruit ripen(fruit a){
	if(a.color == GREEN){
		a.color = YELLOW;
	}
	return a;
}

fruit half_price(fruit a){
	a.price /= 2.0;
	return a;
}

int main(int argc, char* argv[]){
	fruit banana = {.price = 2.20, .color = GREEN, .mass = 50};
	printf("banana.price = %lf\n", banana.price);
	fruit half_price_banana = half_price(banana);
	printf("banana.price (halfprice) = %lf\n", half_price_banana.price);
	return 0;
}
