// To check whether a linked list is pallindrome..
// Working:
//        read the lnked list, push each element to a stack
//        traverse the linked list again compare elements of the linkedlist with pop of  stack
//
// STACK:
// size: 50
//  stack ops: push and pop
//
////////////////////////////////////////////////////////////////////////////////////////////////


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STACKSIZE 50

struct node{
	char character;
	struct node *next;
};

typedef struct node NODE;

int top = 0;

NODE *newNode(char );
NODE *insert(NODE *, char);
void printll(NODE *);
int is_pallindrome(char *, NODE *);
void populate_stack(char *, char c);
int push(char*, char);
char pop(char*);


int main(){

	NODE *root = NULL;
	NODE *root2 = NULL;
	//root = insert(root, 'm');
	int i;
	char stack[STACKSIZE];
	char word[] ={'m','a','l','a','y','a','l','a','m'};
	
	for(i=0; i< sizeof(word)/sizeof(word[0]); i++) // creates linked list with elements in word
		root = insert(root, word[i]);


	
	// returns True/1 if pallindrome
	if(is_pallindrome(stack, root))
		printf("\n\n%s: is a pallindrome\n\n", word);
	else
		printf("\n\n%s is not a pallindrome\n\n", word);
	

    return 0;

}

// returns True on pallindrome
int is_pallindrome(char *stack, NODE *root){
	int flag =0;
	NODE *current = root;
	NODE *temp = root;


	for(;current != NULL; current = current->next) 
		populate_stack(stack, current->character);
	
	
	for(;temp != NULL;temp = temp->next)
		if(temp->character !=  pop(stack)){
			
			printf("inside");
			flag =1;
			break;
		}
    
	if(flag == 1)
		return 0;
	else
		return 1;


}

// A utility to populate the stack
void populate_stack(char *stack, char c){
	top = push(stack, c);
}

// A utility to print the elemenst in the linkedlist
void printll(NODE *root){
	for(;root != NULL; root = root->next)
		printf("%c\t",root->character );

	printf("\n");
}

// Utility used to insert elemets to the end of the linked list
NODE *insert(NODE *root, char c){

	NODE *current = root;
	NODE *node = newNode(c);
	if(root == NULL)
		root = node;
	else{
		for(;current->next != NULL; current=current->next)
			;
		current->next= node;
	}
	return root;
}

// A utility that returns new node
NODE *newNode(char c){
	NODE *new = (NODE *)malloc(sizeof(NODE));
	new->character = c;
	new->next = NULL;

	return new;
}


// The stack push operation
int push(char *stack, char c){
	if(top > STACKSIZE){
		printf("Stack limit reached\n");
		exit(1);
	}
	stack[top] = c;
	top++;
	return top;

}

// The stack pop operation
char pop(char *stack){
	if(top == 0){
		printf("Stack is empty\nError in execution..\tExiting..\n");
		exit(2);
	}
	char c = stack[top-1];
	top--;
	return c;
}