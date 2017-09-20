
// multiple inheritance


#include <iostream>
using namespace std;

class Foo{ protected: int data;};
class Bar1 : public Foo{};
class Bar2 : public Foo{};
class Bar3 : public Bar1, Bar2{
	void method(void){
		data =1 // it can refer to data either in Bar 1or Bar 2 , this is 
		        // called as diamond problem. it is better to refer ike BAr1::data or Bar2::data
		        // over we can use virtual inheritance in Bar1 and Bar2

	}

};