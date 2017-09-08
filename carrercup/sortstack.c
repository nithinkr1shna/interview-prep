// Sort a stack using another stack with no recursion.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 
//  sort a stack using a intermediate variable and another stack.
//  STACK
//  ~~~~~
//  size : 50
//  FIFO 
//  ops: pop and push
//
///////////////////////////////////////////////////////////////////////////


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAXSIZE 50

void push(int *, int, int*);
int pop(int *, int *);
void printstack(int *, int, char *);
int *sort(int *, int , int *, int);
void pop_and_push(int *, int * , int *, int*);
void swap(int *, int *);

int len;

int main(){

	int stack1[MAXSIZE], stack2[MAXSIZE];
	int stack1_top = 0, stack2_top = 0;
	int arr[] = {9999,55, 89, 45, 23, 34, 23,4, 67, 76, 3, 90, 100, 43, 2, 45, 67, 89, 6000, 456, 789, 21, 22, 45, 67,34}, i;
	int data;
	int *sorted_stack;
	
	len = sizeof(arr)/sizeof(arr[0]);

	for(i=0; i<len; i++)
		push(stack1, arr[i], &stack1_top); // populating the first stack

	printstack(stack1, stack1_top, "stack1");
	printf("\n");
	sorted_stack = sort(stack1, stack1_top, stack2, stack2_top);
	printstack(sorted_stack, len, "stack2");
	

    return 0;
}


// utility that sorts the stack to another stack
int *sort(int *stack1, int stack1_top, int *stack2, int stack2_top){

    //initial
	if(stack2_top == 0){
		int data;
		data = pop(stack1, &stack1_top);
		
		push(stack2, data, &stack2_top);
	}
	
	while(1){
		//usleep(50000);
        
		int stk1_d = pop(stack1, &stack1_top);
		
		if(stack2_top == len ){
			break;
		}
		if(stk1_d <= stack2[stack2_top-1]){
			push(stack2, stk1_d, &stack2_top);
			
		}else{
			
            
            printstack(stack1, stack1_top, "stack1");
			printstack(stack2, stack2_top, "stack2");
			printf("\n");
			
            int stk2_d = pop(stack2, &stack2_top);
            push(stack2, stk1_d, &stack2_top);
            push(stack2, stk2_d, &stack2_top);
            

			
			
			while(stack2_top > 0){
				//usleep(5000);
				pop_and_push(stack2, &stack2_top, stack1, &stack1_top);
				

			}
			push(stack2, pop(stack1, &stack1_top), &stack2_top);
			
		}
		


		

	}
	return stack2;

}


// A utility that pops an element from a stack and push the popped element to another stack
void pop_and_push(int *stack2, int *stack2_top, int *stack1, int *stack1_top){

	int data = pop(stack2, stack2_top);
	push(stack1, data, stack1_top);
	
}

// The stack push operation
void push(int *stack, int data, int *top){

	stack[*top] = data;
	
	*top = *top +1;	
}

// A utility used to print stack elements
void printstack(int *stack, int top, char *stack_name){
    printf("%s\t:",stack_name);
	int i;
	for(i=0;i<top;i++)
		printf("%d\t", stack[i]);

	printf("\n");
}


// The stack pop operation
int pop(int *stack, int *top){

	int data = stack[*top-1];
	
	*top = *top -1;
	return data;
}



