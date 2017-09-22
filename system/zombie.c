// a zombie process is created

// when the pid == 0 => child process
// when pid is -ve , forsk() faied

// here when no wait is called, which implies that parent process is not exiting the status of its child, 
// the child already finished executinga dand terminated biut it is still in the process table
// and hence the name ZOMBIE process

#include <stdio.h>
#include <stdlib.h>

int main(){
	pid_t pid;

	if((pid = fork()) >0){
		printf("parent running\n");
		//wait();
		sleep(60);
	}else{
		printf("child running\n");
	}
}