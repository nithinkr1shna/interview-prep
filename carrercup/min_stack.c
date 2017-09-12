// Find min value at any time in a stack O(1)

//  constant time min peek by sacrificing space.
//  keep another stack min_stack, which constains the min values in the stack, 
//  and pops it on the go.


//              bottom--->   ---> ----> -------> ----->  ----->  ---->top

//  stack ::    3       45      67      87      23      11      2       6
//  min_stack:: 3       3       3       3       3       3       2       2


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STACKSIZE 50

struct stack_obj{

	int st[STACKSIZE];
	int top;
};

typedef struct stack_obj stack_t;


void push(stack_t * , int);
int pop(stack_t *);
void initialize(stack_t , stack_t);
void printstack(stack_t );
int get_minimum(int , int);
int get_stack_min(stack_t);
int pop2(stack_t *, stack_t *);

int main(){

	int nums[] = {3,45,67,87,23,11,2,6,7}, i;
    stack_t stack, min_stack;
    
    initialize(stack, min_stack);
	for(i=0; i< sizeof(nums)/ sizeof(nums[0]) ; i++){
		push(&stack, nums[i]);
		if(i == 0){
			push(&min_stack, nums[i]); // min at stack index = 0
		}else{
			if(min_stack.st[i-1] <= nums[i])
				push(&min_stack, min_stack.st[i-1]);
			else
				push(&min_stack, nums[i]);


		}
		
	}

	//  sample driver

	printstack(stack);

	printf("%d\n",pop2(&stack, &min_stack));
	printstack(stack);
	printstack(min_stack);
	printf("min: %d\n",get_stack_min(min_stack) );
	pop2(&stack, &min_stack);
	pop2(&stack, &min_stack);
	printf("min: %d\n",get_stack_min(min_stack) );
	printstack(stack);

    //  end of driver 
	
	return 0;
}

// printd the stack
void printstack(stack_t stack){
	int i;
	for(i=0;i< stack.top ; i++)
		printf("%d\t", stack.st[i]);

	printf("\n");

}

// utility fucntion to get min of two values
int get_minimum(int a, int b){

	return (a > b)? a: b;
}


// return the top of min_stack => min 
int get_stack_min(stack_t stack){
	return stack.st[stack.top-1]; // returns peek value, no pop is done here
}

// push an item into the stack 
void push(stack_t *stack, int item){

	stack_t temp = *stack;
	temp.st[temp.top] = item;
	temp.top++;
	*stack = temp;

}

// return changed stack and data as the popped item
int pop(stack_t *stack){
    
	int item;
	stack_t temp = *stack;
	item = temp.st[temp.top];
	temp.top--;
	*stack = temp;

	return item;

}

// initilaizes stack top points to index zero
void initialize(stack_t stack, stack_t min_stack){
	stack.top =0;
	min_stack.top =0;

}

// pop the stack and updates the min_stack
int pop2(stack_t *stack, stack_t *min_stack){
     
    int item = pop(stack);
    pop(min_stack);

    return item;
}