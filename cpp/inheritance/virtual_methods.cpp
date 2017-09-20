// functiion ifpresent in the inherited class, it will work rather than the function
// in the base class

#include <iostream>
using namespace std;

class Foo {
public:
	//Foo(void);
	void method1(void){ cout<<"Foo: methiod1"<<endl;}
	virtual void method2(void){ cout<<"v_foo:method2"<<endl;}
	
};

class Bar : public Foo {
public:
	//Bar(void);
	void method1(void){cout<<"bar: method1"<<endl;}
	void method2(void){cout<<"bar: methid2"<<endl;}
};


int main(){
	Foo *bar = new Bar();
	bar->method1(); // Foo: methiod1
	bar->method2(); // bar: methid2
}
