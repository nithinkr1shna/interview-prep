// An implementation of a queue using 2 stacks



#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 100


int push(int *, int, int);
int pop(int *, int *);
void display(int *, int *);
void pop_and_push(int *, int, int *, int *);

int main(){
    // stack1 for storing intgers as it comes.
    // stack2 for storing the integers in q order.

	int stack1[MAXSIZE], stack2[MAXSIZE];
	int stack1_top=0, stack2_top=0;
	char choice;
	do{
		printf("Enter 'n' to abort queue operations\n");
		scanf("%c", &choice);
		if(choice != 'n'){
			int operation;
			printf("\n\nSelect operation:\n  1. for enqueue\n  2. for dequeue\n  3. for display next elements \n\n");
			scanf("%d", &operation);
			switch(operation){
				case 1: printf("Enter an integer to Enqueue\n");
				        int to_add;
				        scanf("%d", &to_add);
				        stack1_top = push(stack1, to_add, stack1_top);
				        break;
				case 2: if(stack2_top == 0){
				            pop_and_push(stack1, stack1_top, stack2, &stack2_top);
				            pop(stack2, &stack2_top);
				        }else{
				        	pop(stack2, &stack2_top);
				        }
				        break;
				case 3: display(stack2, &stack2_top);
				        break;
			}

		}




	}while(choice != 'n');


	return 0;
}

// utility to display the elements in second stack
void display(int *stack, int *top){

    //printf("IN display top: %d\n", *top);
	int i;
	for(i=0; i<*top-1 ;i++){
		printf("%d\t", stack[i]);
	}
	printf("\n\n");
}

// utility to pop from first stack and puching to second stack
void pop_and_push(int *stk1, int stk1_top, int *stk2, int* stk2_top){
	int data;
	while(stk1_top 	> 0){
		data = pop(stk1, &stk1_top);
		printf("popped and pushed  %d\n", data);
		*stk2_top = push(stk2, data, *stk2_top);
		stk1_top--;

	}

}

//utiity to push into stack and return the top
int push(int *stck, int data, int top){

	stck[top] = data;
	top++;
	return top;
	
}

// utility to pop and return data
int pop(int *stck, int* stck_top){

	int data = stck[*stck_top -1];
	printf("Popped %d\n", data);
	*stck_top--;
	printf("pop stack top:%d\n", *stck_top );

	
	return data;

}