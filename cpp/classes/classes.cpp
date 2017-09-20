// An extended concept of data type
// I can hold both data and functions.
#include<iostream>
using namespace std;

int main(int argc, char **argv){

class Foo{   // pvt
	int attribute;
	int fun(void){};
};

struct Bar{   // pblic
	int attribute;
	int fun(void){};

};

//Foo foo;
//foo.attribute = 1;

Bar bar;
bar.attribute = 1;
cout<< bar.attribute<< endl;

}