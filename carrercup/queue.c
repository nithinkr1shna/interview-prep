// An toy implementation of a QUEUE
//
// Operations:
//       1. Dequeue : delete from Q
//       2. Enqueue : insert to Q
//  
// QUEUE:
// ~~~~~
// size : 50
// FIFO
// rear : rear end
// front: front end 


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 50


int rear=0, front = 0;


void printq(int *);
int is_full(int *);
int is_empty(int *);
void enqueue(int *, int);
void dequeue(int *);

int main(){

	int queue[MAXSIZE];
	
	
	enqueue(queue, 4);
	enqueue(queue, 5);
	printq(queue);
	dequeue(queue);
	dequeue(queue);
	dequeue(queue);
	printq(queue);

}


// utility to print the queue elements;
void printq(int *q){
	int i;
	for(i = rear; i< front ; i++){
		printf("%d\t",q[i]);
	}
	printf("\n");

}

// utility to check whether the queue is full
int is_full(int *q){
	return (front == MAXSIZE-1 || rear == MAXSIZE);

}

// utility to check whether the queue is empty
int is_empty(int *q){
	return (front - rear == 0); 
}

//  An utility to delete from queue
void dequeue(int *q){
	if(rear == MAXSIZE){
		printf("Error in Queue");
		exit(1);
	}
	if(is_empty(q)){
        printf("The queue is empty\n");
		
	}else{
		printf("\nDeleted %d\n", q[rear]);
	    rear++;
	}
	
}

// A utility to insert to queue
void enqueue(int *q, int data){

    if(is_full(q)){
    	printf("The queue is full \n");
    }else{
	    q[front] = data;
	    front++;
    }
}