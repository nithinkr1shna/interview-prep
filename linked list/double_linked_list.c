// IMplementation double linkde list

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
	struct node *prev;
};

typedef struct node NODE;

void printll(NODE *);
NODE *insert(NODE *, int);
NODE *newNode(int);

int main(){

	NODE *root = NULL;
	root = insert(root, 34);
	root = insert(root, 4);
	root = insert(root, 54);
    printll(root);
	return 0;

}

NODE *insert(NODE *root, int key){

    NODE *current = root;
	NODE *temp = newNode(key);
	
	if(root == NULL)
		root = temp;
	else{

		for(;current->next != NULL; current = current->next)
			;
		current->next = temp;
		temp->prev = current;

	}
	//printf("%d\t", current->prev->data);
	return root;

}

NODE *newNode(int key){

	NODE *new = (NODE *)malloc(sizeof(NODE));
	if(new == NULL){
		printf("Error in malloc...Exiting..\n");
		exit(1);
	}
	new->data = key;
	new->next = NULL;
	new->prev = NULL;

	return new;
}

void printll(NODE *root){

	for(;root != NULL; root = root->next){
		printf("%d\t", root->data);

	}
	printf("\n");
	//printf("%d\t", root->prev->data );
}