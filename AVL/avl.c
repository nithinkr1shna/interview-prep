// An AVL implementation : insertion ONLY

// An AVL tree is balanced either by using,
//  1. Right- Rotation
//  2. Left- Rotation


// ??????????????????????????????????????????????
// ???                                        ???
// ???    Adelson-Velskii and Landis : AVL    ???
// ???                                        ???
// ??????????????????????????????????????????????

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// struct node 
struct node{

   int key;
   struct node *left;
   struct node *right;
   int height;
};

typedef struct node NODE;

// function declarations
NODE *leftrotate(NODE *);
NODE *rightrotate(NODE *);
NODE *insert(NODE *,int );
NODE *newNode(int);
NODE *inorder(NODE*);
int max(int, int);
int height(NODE *);


int main(){

    NODE *root = NULL;
    int arr[] ={34, 78, 90, 45, 67, 89, 12, 342}, i;
    root = insert(root , 40);
    for(i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
        
        insert(root, arr[i]);
    }

    inorder(root);
    printf("\n");

	return 0;
}

// utility to add new node maintaining the searching property.
NODE *insert(NODE *root, int key){

	if(root == NULL)
		return newNode(key);
	else if(key < root->key)
		root->left = insert(root->left, key);
	else if(key > root->key)
		root->right = insert(root->right, key);
	else{
		printf("equal nodes are not allowed\n");
	    return root;
    }
   
    root->height = 1 + max(height(root->left), height(root->right));
    
    int balance = get_bal(root);
    // there are four cases if this node is unbalanced.
  

    //left left case
    if(balance > 1 && key < root->left->key)
    	return rightrotate(root);
    // right right case
    if(balance < -1 && key > root->right->key)
    	return leftrotate(root);
    //left right case
    if(balance > 1 && key > root->left->key){
    	root->left = leftrotate(root->left);
    	return rightrotate(root);
    }
    // right left case
    if(balance < -1 && key < root->right->key){
    	root->right = rightrotate(root->right);
    	return leftrotate(root);
    }
    




	return root;
}

NODE *leftrotate(NODE *x){

	NODE *y = x->right;
	NODE *T2 = y->left;

    // perform rotation
	y->left = x;
	x->right = T2;

    // update heights
	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right))+ 1;

    // return new root;
	return y;

}

NODE *rightrotate(NODE *y){

	NODE *x = y->left;
	NODE *T2 = x->right;

    // perform rotation
	x->right = y;
	y->left = T2;

    // update heights
	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;

    // return new root
	return x;
}

// helper utility that returns new node with key = key and height initially one.
NODE *newNode(int key){

	NODE *node = (NODE *)malloc(sizeof(NODE));
	node->key = key;
	node->height = 1; // height is initially one.
	node->left = node->right = NULL;

	return node;
}


// utility that helps in printing the tree in inorder or sorted order(increasing).
NODE *inorder(NODE *node){

	if(node != NULL){

		inorder(node->left);
		printf("%d\t", node->key);
		inorder(node->right);
	}

}




//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!   HELPER FUNCTIONS  !!!!!!!!!!!!!!!!!!!


// helper function that returns the max of two
int max(int a, int b){

	return (a> b)? a : b;
}

// utility that returns the height of the node
int height(NODE *node){

      if (node == NULL)
      	return 0;
      else
      	return node->height;
}


// utility that return the balance factor
int get_bal(NODE *node){

	if(node == NULL)
		return 0;
	else 
		return height(node->left)- height(node->right);
}