// stack additional operations like , peeklowestelement(), peekhighestelement(), peekmiddlelement()

// STCK
//~~~~~~
// size  50
// ops push
//     pop
//     peek_lowest_elem    --> returns lowest elem
//     peek_highest_elem   --> returns highest elem
//     peek_middleL_elem   --> returns (size/2 + 1)th lowest elem
// 
// order : FILO



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX 50  // max size of the satck.


struct stack_obj{

	int st[MAX];
	int top;

};


typedef struct stack_obj stack_t;

void init(stack_t );
void push(stack_t *, int);
void printstack(stack_t);
int pop(stack_t *);

int peek_lowest_elem(stack_t);
int peek_highest_elem(stack_t);
int peek_middleL_elem(stack_t);

int main(){

	stack_t stack;

    init(stack);
	push(&stack, 6);
	push(&stack, 7);
	push(&stack, 3);
	push(&stack, 2);
	push(&stack, 5);
	//printstack(stack);
	//pop(&stack);
	printstack(stack);
	printf("\nLowest : %d\n", peek_lowest_elem(stack));
	printf("Highest: %d\n",peek_highest_elem(stack));
	printf("Middle Lowest: %d\n",peek_middleL_elem(stack));



	return 0;

}

// The stack push operation
void push(stack_t *stack, int item){

    stack_t temp = *stack;
	temp.st[temp.top] = item;
	temp.top++;
	*stack = temp;

}


// The stack pop operation
int pop(stack_t *stack){

    stack_t temp = *stack;
	int item = temp.st[temp.top];
	temp.top--;
	*stack = temp;

	return item;

}


// initializes the top of stack points to zeroth index
void init(stack_t stack){

	stack.top = 0;
	
}

// prints the stack 
void printstack(stack_t stack){
	int i;
	for(i=0; i < stack.top; i++)
		printf("%d\t", stack.st[i]);

	printf("\n");
}

// returns the lowest elem in the stack
int peek_lowest_elem(stack_t stack){

	int lowest=0, i;
	lowest = stack.st[stack.top-1];
	for(i =0; i < stack.top; i++){
		if(stack.st[i] < lowest)
			lowest = stack.st[i];

	}
	return lowest;
}


// returns highest elem in the stack
int peek_highest_elem(stack_t stack){
	int highest =stack.st[stack.top -1], i;
	for(i=0; i< stack.top; i++)
		if(stack.st[i] > highest)
			highest = stack.st[i];

	return highest;
}

// return s middle lowest elem in the stack
int peek_middleL_elem(stack_t stack){
	int size = (stack.top -1 )/2 +1, i, lowest =stack.st[size];
	
	for(i =0; i<size;i++)
		if(lowest > stack.st[i])
			lowest = stack.st[i];

	return lowest;
}