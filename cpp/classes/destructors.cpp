// there can nly be a singe destructor for a class

#include <iostream>
using namespace std;

class Foo{
public:
	~Foo(void){
		cout<< "destructor called"<<endl;
	}
};

int main(int argc, char **argv){
	Foo foo();
	return 0;
}