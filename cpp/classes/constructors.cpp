// constructosrs or init 

#include <iostream>
using namespace std;



class Foo{
public:
	Foo(void){
		cout<<"FOO constructor 1 is called"<<endl;
	}
	Foo(int v){
        cout<< "FOO constructor 2 is called"<<endl;
	}

};

int main(int argc, char **argv){
	Foo foo_1, foo_2(2);
	return 0;
}

