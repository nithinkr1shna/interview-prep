// reverse a string using stack @recursion


#include <stdio.h>


void rev(void);

int main(){

	printf("Enter the string\n");
	rev();

	return 0;
}

void rev(){

	char c;
	scanf("%c", &c);

	if(c != '\n'){
		rev();
		printf("%c", c);
	}
	
}