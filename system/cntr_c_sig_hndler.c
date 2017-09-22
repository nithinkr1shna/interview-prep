#include <stdio.h>
#include <stdlib.h>
#include <signal.h>


void signal_handler(){
	printf("signal handler\n");
}

int main(){
	signal(SIGINT, signal_handler);
	sleep(100);
}