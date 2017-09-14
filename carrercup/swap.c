// swaptwo variables with no temp variable

#include <stdio.h>

void swap(int *, int *);

int main(){

	int a = 5;
	int b = 9;
	printf("a: %d\t b: %d\n", a, b);
	swap(&a, &b);
	printf("After swap\na: %d\t b: %d\n", a, b);


    return 0;
}


void swap(int *a, int *b){
	
	*a =*a+*b; //5+9 = 14
	*b = *a- *b;
	*a = *a -*b;
}