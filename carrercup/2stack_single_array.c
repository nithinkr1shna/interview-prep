// implement two stacks using a single array
// used dynamic return from pop with the use of union nested struct

// STACK
//~~~~~~~
// size : 100 (shared array by two stacks(using two pointers, top1 and top2))
// FILO


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

// struct for creating stack
struct stack_obj{
	int st[MAX];
	int top1;
	int top2;
};

// union holds msg/data
union pop_return{
	char *msg;
	int data;

}u;

// union nested struct used for return value from pop function
struct pop_return_type{
	union pop_return u;
	char *type; // m for msg and d for data 
};

typedef struct stack_obj stack_t;
typedef struct pop_return_type pop_return_t;

//function declaration
void init(stack_t *);
void push(stack_t *, int , char *);
pop_return_t pop(stack_t *, char *);
void printstack(stack_t);
void printpop(pop_return_t );


// sample driver code
int main(){

	stack_t stack;
	pop_return_t value;
	init(&stack);
	push(&stack, 1, "stack1");
	push(&stack, 2, "stack1");
	push(&stack, 4, "stack2");
	push(&stack, 5, "stack2");
	printstack(stack);
	value = pop(&stack,"stack1");
	printpop(value);
	printstack(stack);
}


// print the poped value either integer or the string return: "the stack is empty " message
void printpop(pop_return_t value){
	if(strcmp(value.type,"d") == 0)
		printf("popped value is: %d\n", value.u.data);
	else
		printf("%s\n",value.u.msg);
}

// stack1 top to be 0 and stack2 top to be 49; 
void init(stack_t *stack){
	stack_t temp = *stack;
	temp.top1 = 0;
	temp.top2 = MAX -1;
	*stack = temp;

}

// prints both stack within the same array
void printstack(stack_t stack){
	int i;
	printf("stack1\n");
	for(i=0;i< stack.top1 ;i++)
		printf("%d\t" ,stack.st[i]);
	printf("\nstack2\n");
	for(i=MAX-1; i >stack.top2; i--)
		printf("%d\t",stack.st[i]);
	printf("\n");
}


// The stack push operation push item into the stack mentioned
void push(stack_t *stack, int item, char *stack_name){
	stack_t temp =*stack;
	if(temp.top2 - temp.top1 < 2){
		printf("Can't push : stack overflow\n");
	}
	if(strcmp(stack_name, "stack1") == 0){
		temp.st[temp.top1] = item;
		temp.top1++;
		*stack = temp;
	}else{ // stack2
		temp.st[temp.top2] = item;
		temp.top2--;
		*stack = temp;
	}
		

}


// returns a union nested struct of type pop_return_type with union fields (data(int type) or msg(char * type))
pop_return_t pop(stack_t *stack, char *stack_name){
	pop_return_t return_val; // union nested struct
	stack_t temp = *stack;

	if(strcmp(stack_name, "stack1") == 0){
		if(temp.top1 == 0){
			return_val.u.msg = "stack 1 is empty";
			return_val.type ="m"; // return type contains string or char *
		}else{
		    int item = temp.st[temp.top1-1];
		    temp.top1--;
		    *stack = temp;
		    return_val.u.data = item;
		    return_val.type = "d"; // return type contains data or integer type
	    }
	}else{
		if(temp.top2 == MAX-1){
		return_val.u.msg = "stack 2 is empty";
		return_val.type ="m";
	}else{
	    int item = temp.st[temp.top2+1];
	    temp.top2++;
	    *stack = temp;
	    return_val.u.data = item;
	    return_val.type ="d";
       }

    }

return return_val;
}