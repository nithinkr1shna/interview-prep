// fucnction overloading refers to the possibility of creating muultiple
// functions with same name but diff signature

#include <iostream>
using namespace std;

float add(double a, double b){
	return a+b;
}

int add(int a, int b){
	return a+b;
}

int main(int argc, char **argv){

	cout <<add(4,5)<<endl
	     <<add(8.3,5.6)<< endl;
}