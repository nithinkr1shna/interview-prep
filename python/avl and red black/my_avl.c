// avl implementation : insertion only

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *left, *right;
	int height;

};

typedef struct node NODE;


NODE *insert(NODE *, int);
NODE *newNode(int);
int max(int, int);
int get_bal(NODE *);
int height(NODE *);
void inorder(NODE *);
NODE *rotateright(NODE *);
NODE *rotateleft(NODE *);

int main(int argc, char **argv){


    NODE *root = NULL;
    int nums[] = {5,91,34,78,12,2,9}, i;
    for(i=0;i<sizeof(nums)/sizeof(nums[0]);i++)
    	root = insert(root, nums[i]);

    inorder(root);
    printf("\n");

	return 0;
}

NODE *insert(NODE *root, int data){

	if(root == NULL)
		return newNode(data);
	else if(data < root->data)
		root->left = insert(root->left, data);
	else if(data > root->data)
		root->right = insert(root->right, data);
	else{
		printf("ERROR: No duplicate allowed :%d\n",data);
		exit(1);
	}

	root->height = 1 + max(height(root->left), height(root->right));

	int balance = get_bal(root);

	if(balance > 1){
		// either left left or left right
		if(height(root->left->left) >= height(root->left->right)){ //LL
			return rotateright(root);
		}else{
			root->left = rotateleft(root->left); //LR
			return rotateright(root);
		}

	}else{
		if(balance < -1){
			if(height(root->right->right)  > height(root->right->left)){ // RR
				return rotateleft(root);

			}else{
				root->right = rotateright(root->right);  //RL
				return rotateleft(root);
			}
		}
	}




	return root;
}

NODE *rotateleft(NODE *x){
	NODE *y = x->right;
	NODE *T2 = y->left;

	y->left = x;
	x->right = T2;

	x->height = max(height(x->left), height(x->right)) +1 ;
	y->height = max(height(y->left), height(y->right)) + 1;

	return y;
}

NODE *rotateright(NODE *y){
	NODE *x = y->left;
	NODE *T2= x->right;

	x->right = y;
	y->left = T2;

	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;

	return x;
}


int max(int a, int b){
	if(a > b)
		return a;
	else
		return b;
}

int get_bal(NODE *root){
	if( root == NULL)
		return 0;
	else
		return height(root->left) - height(root->right);
}

int height(NODE *root){
	if(root == NULL)
		return 0;
	else
		return root->height;
}

NODE *newNode(int item){

	NODE *new = (NODE *)malloc(sizeof(NODE));
	new->data = item;
	new->left = new->right = NULL;
	new->height = 0;

	return new;

}


void inorder(NODE *root){
	if( root != NULL){
		inorder(root->left);
		printf("%d\t", root->data);
		inorder(root->right);
	}
}