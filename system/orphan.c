// creating a orphan process
// an orphan process is immmediately adopted by the init process/ 


// here we can see that the parent process exits before the parent, and hence the parent dies and the child 
// becomes an orphan.. This orphan is immediately adopted by the init process
#include <stdio.h>
#include <stdlib.h>


int main(){
	if(fork() >0){
		printf("parent process\n");
	}else{
		sleep(10);
		printf("child process\n");
	}
}
