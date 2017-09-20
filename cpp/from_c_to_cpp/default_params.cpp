

// use of default params in cpp

#include <iostream>
using namespace std;
float fun(float a=0, float b=1, float c=2){
	return a+b+c;
}

int main(int argc, char **argv){

	cout<< fun(1)<< endl // single param
	    << fun(1,2) <<endl  // 2 params
	    << fun(1,2,3) << endl // 3 params
	    << fun() <<endl; // no params

}

