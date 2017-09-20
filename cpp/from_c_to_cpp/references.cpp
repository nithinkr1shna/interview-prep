
// references allows to declare alias to another variable. 
// as long as the aliased variabel lives, we can use the alias

#include <iostream>

int main(int argc, char **argv){

	int x;
	int& ref = x; // ref is a refrence to x

	ref = 42;
	std::cout << x<< std::endl;

}