#include <iostream>

int main(int argc, char **argv){

	int *a = new int;
	delete a;

	int *b = new int[5];
	delete [] b;

}