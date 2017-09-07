// A stack implementation in c
// each stack element is of type struct.
// Operatons:
//          1. push(stack, item)
//          2. pop(stack);
//
// STACK:
// ~~~~~~
//
// size : 50
// top  : top is the top of the satck
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{

    int data1;
    int data2;
};

typedef struct node NODE;



void pop(NODE **);
void push(NODE **, NODE *);
NODE *newNode(int , int);
void printstack(NODE **);

int top = 0;

int main(){

	NODE *stack[50];
	push(stack, newNode(1, 2));
	push(stack, newNode(5, 6));
	printstack(stack);
	pop(stack);
	printstack(stack);

    return 0;
}


// utility to pop the the stack
void pop(NODE **stack){
    
    printf("\n\nPOPPED\ndata1: %d\t data2: %d", stack[top-1]->data1, stack[top-1]->data2);
	top--;
	
}

//utility to push an item into the top of the satck
void push(NODE **stack, NODE *node){
	
	stack[top] = node;
	top++;

}

// utility to print the stack
void printstack(NODE **stack){
	
	int i;
	printf("\n\n-------------------------\n");
	printf("STACK\n");
	for(i=0; i<top; i++)
		printf("\ndata1: %d\t data2: %d\n",stack[i]->data1, stack[i]->data2);
	printf("-------------------------\n");
}


// utility which returns a new node of type NODE 
NODE *newNode(int data1, int data2){

	NODE *new = (NODE*)malloc(sizeof(NODE));
	new->data1 = data1;
	new->data2 = data2;

	return new;
}