// Linked List implementation
// ops:
//     1. insert to end [NODE * insert(NODE*, int)]
//     2. 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{

   int value;
   struct node *next;
};


typedef struct node NODE;

NODE *reverse_recursive(NODE *);
NODE *reverse_iterative(NODE *);
NODE *insert(NODE*, int);
NODE *newNode(int);
NODE *delete_node(NODE **, int );
void printll(NODE*);

int main(){

    int arr[]={34, 88, 90, 32, 56, 78}, i;
	NODE *root = NULL; // empty linked list
	root = insert(root, 20);

	for(i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
		insert(root, arr[i]);
	printll(root);
	//root = reverse_iterative(root);
	//printll(root);
	//root = reverse_recursive(root);
	//printll(root);
	root = delete_node(&root, 78);
    printll(root);
    root = delete_node(&root, 20);
    printll(root);
    root = delete_node(&root, 32);
    printll(root);




}

// Function for inserting new nodes to the end O(N), N: size of linked list
NODE *insert(NODE *root, int value){

	NODE *temp = newNode(value);
	NODE *current = root;
	if(root == NULL)
		root = temp;
	else{
		for(;current->next != NULL; current = current->next)
			;
		current->next = temp;
	}



	return root;



}



// utility function which returns a new node with given value as node->value
NODE *newNode(int data){

	NODE *new = (NODE*)malloc(sizeof(NODE));
	new->value = data;
	new->next = NULL;

	return new;


}


// A utility function to print the linked list
void printll(NODE *root){

	NODE *current = root;
	for(;current != NULL; current = current->next)
		printf("%d\t", current->value);

	printf("\n");
}


// reverse the linked list iteratively
NODE *reverse_iterative(NODE *root){

	NODE *current = root;
	NODE *prev = NULL;
	NODE *next;
	for(;current != NULL; ){
		next = current->next;
		current->next = prev;
		prev= current;
		current= next;



	}

	return prev;
}

// utility to reverse a linked list in recursive manner
NODE *reverse_recursive(NODE *root){

	NODE *first = root;
	NODE *rest;

	if(first == NULL)
		return;
	if(first->next == NULL)
		return first;

	rest = reverse_recursive(first->next);
	first->next->next = first;
	first->next = NULL;

	return rest;



}


// utility to delete Nth node from a linked list;

NODE *delete_node(NODE **head_Ref, int key){

	NODE *current = *head_Ref;
	NODE *prev;
	// case when the node is the first node
	printf("\nTrying to delete node with value: %d\n", key);
	if(current->value == key){
		//printf("current>key %d\n",current->value );
		*head_Ref = current->next;
		free(current); 
		printf("Successfully deleted %d\n", key);
	}else{
		
		for(;current != NULL; current= current->next){
			if(current->value == key){
				// if the node is the last node
				if(current->next == NULL){
					
					prev->next = NULL;
					free(current);
					

				}else{
					// if the node is in between
					prev->next = current->next;
					free(current);
					
				}
				printf("Successfully deleted %d\n", key);
				break;
			}
			prev = current;
		}

	}


    return *head_Ref;
} 