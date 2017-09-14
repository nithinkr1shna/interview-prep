// Program to detect loops in a linked list

// concept used:
// +++++++++++++
// 
// store the address of each node in a array, 
// if address already present in hash table >> loop present else no loops


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HASH_KEY 25
#define MAX_SIZE 200

struct node{

	int data;
	struct node *next;

};



typedef struct node NODE;

NODE *insert(NODE *, int);
NODE *newNode(int);
NODE *createloop(NODE *);
void printll(NODE *);
char *detectloops(void);
void add_address(int *, int );

int address_store[MAX_SIZE];

int main(){

	NODE *root = NULL;
	int i, nums[] ={1, 8, 9, 2, 3, 20};
	root = insert(root, nums[0]);
    for(i=1;i<sizeof(nums)/sizeof(nums[0]);i++)
    	insert(root, nums[i]);

    printll(root);

    root = createloop(root);

    //printll(root);

    printf("\n%s\n",detectloops());



}



char *detectloops(){
	int i, k;
	for(i=0 ;i< MAX_SIZE; i++)
		for(k =i+1; k< MAX_SIZE ;k++)
			if(address_store[i] == address_store[k]){
				printf("%d : %d\n", address_store[i], address_store[k]);
				return "loops present";
			}
		

	return "no loops";

	

}

void add_address(int *address_store, int address){

	static int i =0;
	int k;
	address_store[i++] = address;
	printf("\n");
	for(k=0; k< i; k++)
		printf("%d\t",address_store[k]);


}

NODE *insert(NODE *root, int data){
	NODE *new = newNode(data);
	
	if(root == NULL){
		root = new;	
		add_address(address_store, root);

	}

	else{
		NODE *current = root;
		for(;current->next != NULL; current=current->next)
			;
		current->next=new;
		add_address(address_store, current->next);
	}

	return root;
}

NODE *createloop(NODE *root){
	NODE *current = root;
	for(;current->next != NULL; current = current->next)
		;
	current->next = root;
	add_address(address_store, current->next);

	return root;
}

void printll(NODE *root){
	NODE *current = root;
	for(;current != NULL; current = current->next)
		printf("%d\t",current->data);

	printf("\n");
}



NODE *newNode(int data){

	NODE *new = (NODE*)malloc(sizeof(NODE));
	new->data = data;
	new->next = NULL;

	return new;
}