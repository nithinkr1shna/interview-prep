//namespace can be used to group classes or fucntions under a single scope

#include <iostream>
using namespace std;

namespace first {int var = 5;}
namespace second {int var = 3;}

int main(int argc, char **argv){

	cout<< first::var<<endl<<second::var<<endl;

}