// A program to check whether a string has brackets properly placed.
// Used stack to implement this.

// STACK
// ~~~~~

// Size : 50
// FILO



#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STACK_SIZE 50

struct stack_obj{
	char st[STACK_SIZE];
	int top;

};

typedef struct stack_obj stack_t;

char *check_sanity(char *);
void init(stack_t *);
int is_bracket(char *);
void push(stack_t *, char);
char pop(stack_t *);
int is_pair(char , char );

void printstack(stack_t);

int main(){

    char *string1 = "{hello, hai[what]}[that is good]{}"; 
    char *string2 = "{what is goin on []}{";

    printf("\n%s: %s\n",string1, check_sanity(string1));
    printf("%s: %s\n\n",string2, check_sanity(string2	));

	return 0;
}


// Returns tring stating whether the passed string is sane w.r.t brackets
char *check_sanity(char *string){
	
	stack_t stack;
	char *p; 
	p = string;
	init(&stack); // inits top points to zero
	while( *p != '\0'){
      
		if(is_bracket(p)){
			
			if(stack.top == 0){
				push(&stack, *p);
			}else{
				
				if(is_pair(stack.st[stack.top-1], *p)){
					
					pop(&stack);
				}else{
					
					push(&stack, *p);
				}
			}
		}

		
		p++;
	}

	//printstack(stack);

	if(stack.top == 0)
		return "brackets are properly placed";
	else
		return "brackets are not properly placed";
	
	

	

}

// The stack push operation.
void push(stack_t *stack, char item){

	stack_t temp = *stack;
	temp.st[temp.top] = item;
	temp.top++;

	*stack= temp;
}

// The stack pop operation
char pop(stack_t *stack){

	stack_t temp = *stack;
	int item = temp.st[temp.top-1];
	temp.top--;
	*stack = temp;

	return item;
}

// returns true if 'a' and 'b' are pairs
int is_pair(char a, char b){
    
	if((a == '{' && b == '}') 
		 || (a == '[' && b == ']')
		   || (a == '(' && b == ')') )
		return 1;
    
	return 0;

}

// utility to print the stack
void printstack(stack_t stack){
	int i;
	for(i=0; i < stack.top; i++)
		printf("%c\t", stack.st[i]);

	printf("\n");
}


// returns true if bracket else false
int is_bracket(char *c){
	
	if(strncmp(c,"{", 1)== 0 || strncmp(c, "}", 1) == 0
		|| strncmp(c, "[", 1) == 0 || strncmp(c, "]", 1) == 0
		  || strncmp(c, ")", 1) == 0 || strncmp(c, "(", 1) == 0)
		return 1;
	return 0;

}

// initialize the satck top points to index zero
void init(stack_t *stack){
	stack_t temp = *stack;
	temp.top = 0;
	*stack = temp;
}