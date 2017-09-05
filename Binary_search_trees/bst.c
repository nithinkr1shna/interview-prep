//Binary search tree
//~~~~~~~~~~~~~~~~~~

// In binary search tree , the node on the left has value less than parent
// the node on the right has value greater than parent.
//
//                  [50]
//                  /  \
//                 /    \
//                [30]   [70]
//               /  \    /  \
//            [20] [40][60] [80]
//                 
//              
//  op1. delete(20)
//  op2. delete(30)
//  op3. delete(50)
// 
// IS a binary search tree
// FOr doubts refer : http://www.geeksforgeeks.org/binary-search-tree-set-2-delete/



#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// each node as a struct

struct node {
	int key;
	struct node *left, *right;
};

typedef struct node NODE;

void postorder(NODE *);
void preorder(NODE *);
void inorder(NODE *);
NODE *deleteNode(NODE*, int);
NODE *newNode(int);
NODE *insert(NODE*, int);
NODE *minVal(NODE*);
char *is_node(NODE*, int);

int main(){
    int keys[] ={30,20,40,80,60,70}, i;
    char *val;	
	NODE *root = NULL;
	root = insert(root, 50);
	for(i=0;i<(sizeof(keys)/sizeof(keys[0])) ;i++)
		insert(root, keys[i]);

	inorder(root);
	val = is_node(root, 160); 
	printf("%s\n", val);
	deleteNode(root, 60);

	printf("INORDER\n");	
	inorder(root);
	printf("PREORDER\n");
	preorder(root);
	printf("POST ORDER\n");
	postorder(root);
	
}



// recursive insert function.
NODE* insert(NODE *node, int key){ 
	if(node == NULL)
		return newNode(key); // if the node is empty.

	if(key < node->key) // if lt left check in children of current key
		node->left = insert(node->left , key);
	else if(key > node->key)
		node->right = insert(node->right, key);

	return node;


}

// returns true if node is present in the BST
char *is_node(NODE *root, int key){

	if(root == NULL || root->key == key)
		return "True";
	else if(key < root->key)
		is_node(root->left, key);
	else if(key > root->key)
		is_node(root->right, key);
	
}

NODE *newNode(int key){ // returns new node with key = key of type NODE.

	NODE* new = (NODE*)malloc(sizeof(NODE));
	new->key = key;
	new->left = new->right = NULL;

	return new;
}

void inorder(NODE *root){ // printd the tree elements in increasing fashion.

    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}

void preorder(NODE *root){

	if(root != NULL){

		printf("%d\n", root->key);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(NODE *root){

	if(root != NULL){

		postorder(root->left);
		postorder(root->right);
		printf("%d\n", root->key);
	}
}


NODE *deleteNode(NODE *root, int key){

	if(root == NULL)
		return root;
	if(key < root->key)
		root->left = deleteNode(root->left, key);
	else if(key > root->key)
		root->right = deleteNode(root->right, key);
	else{
         //at this point we ereached at the required key to delete
		// there can be 3 conditions 1. the node to dlete cna be a leaf node -|>
		                           //2. the node can have a single child     -|> that with no or single child.
		                           //3. the node can have both children

		// with no or single child.

		if(root->left == NULL){
			NODE *temp = root->right;
			free(root);
			return temp;
		}else if(root->right == NULL){

			NODE *temp = root->left;
			free(root);
			return temp;
		}

        //whwn have two children 
        NODE *temp = minVal(root->right);  // i didnt get this.
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
		
	}
	return root;
}

NODE *minVal(NODE *node){

    NODE* current = node;
    while(current->left != NULL)
    	current = current->left;

	return current;
}