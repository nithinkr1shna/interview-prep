// red black tree: insertion 


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdlib.h>



struct node{
	int data;
	struct node *left, *right, *parent;
	char color;

};

typedef struct node NODE;

void insert(int);
NODE *newNode(int );
NODE *BSTinsert(NODE *, NODE *);
void inorder(NODE *);
void fixviolation(NODE *, NODE *);
void swapcolor(NODE *, NODE *);
void rotateRight(NODE *,NODE *);
void rotateLeft(NODE *, NODE *);

NODE *root = NULL;
int main(int argc, char **argv){

	int nums[] = {7,6,5,4,3,2,1}, i;
	for(i=0; i<sizeof(nums)/sizeof(nums[0]); i++)
		insert(nums[i]);

	inorder(root);
	printf("\n");


}

// insert fucntion which handles BST insert and fix the violation on each insert if any 
void insert(int data){
	NODE *pt = newNode(data);

	root = BSTinsert(root, pt);
	fixviolation(root, pt);

}

// the genaeral binary search tree insertion along wih the updation of parent field.
NODE *BSTinsert(NODE *root, NODE *pt){

	if(root == NULL)
		return pt;
	if(pt->data < root->data){
		root->left = BSTinsert(root->left, pt);
		root->left->parent = root;
	}else if(pt->data > root->data){
		root->right = BSTinsert(root->right, pt);
		root->right->parent = root;
	}

	return root;
}


// the fix violatipn funtion, responsible for keeping the red-black tree property.
void fixviolation(NODE *root, NODE *pt){
	NODE *parent_pt =NULL, *grand_parent_pt = NULL;
	while((pt != root) && (pt->color != 'b') && (pt->parent->color == 'r')){

		parent_pt = pt->parent;
		grand_parent_pt = pt->parent->parent;

		// case A:
		// parent of pt is left child of grand_parent of pt
		if(parent_pt == grand_parent_pt->right){

			NODE *uncle_pt = grand_parent_pt->right;

			//case 1
			// The uncle of pt is also red 
			// only recoloring required
			if(uncle_pt != NULL && uncle_pt->color == 'r'){

				grand_parent_pt->color = 'r';
				parent_pt->color = 'b';
				uncle_pt->color = 'b';
				pt = grand_parent_pt;
			}else{
				//case 2
				//pt is right chid of its parent
				//LRot required
				if(pt == parent_pt->right){
					rotateLeft(root, parent_pt);
					pt = parent_pt;
					parent_pt = pt->parent;
				}
				// case 3
				// pt is left chils of ots parent
				// RRot required
				rotateRight(root, grand_parent_pt);
				swapcolor(parent_pt, grand_parent_pt);
				pt = parent_pt;
			}
		}else{
			//case B
			//parent of pt is right child of grand-parent of pt
			NODE *uncle_pt = grand_parent_pt->left;
			// case 1
			// the uncle of pt is alsoe red
			// only recolorin req
			if((uncle_pt != NULL) && (uncle_pt-> color == 'r')){
				grand_parent_pt->color = 'r';
				parent_pt->color = 'b';
				uncle_pt->color = 'b';
				pt = grand_parent_pt;
			}else{
				//case 2
				// pt is left child of its parent
				// rightRot is req
				if(pt == parent_pt->left){
					rotateRight(root, parent_pt);
					pt = parent_pt;
					parent_pt = pt->parent;
				}
				// case 3
				//pt is right child of its parent
				//leftrot req
				rotateLeft(root, grand_parent_pt);
				swapcolor(parent_pt, grand_parent_pt);
				pt = parent_pt;
			}
		}
	}
	root->color = 'b';
}


// creates a new node of type NODE and returns 
NODE *newNode(int data){
	NODE *new = (NODE*)malloc(sizeof(NODE));

	new->data = data;
	new->left = new->right = NULL;
	new->color = 'r';

	return new;
}

// the helper rotateleft operation[req by fixviolation function]
void rotateLeft(NODE *root, NODE *pt){

    NODE *pt_right = pt->right;
 
    pt->right = pt_right->left;
 
    if (pt->right != NULL)
        pt->right->parent = pt;
 
    pt_right->parent = pt->parent;
 
    if (pt->parent == NULL)
        root = pt_right;
 
    else if (pt == pt->parent->left)
        pt->parent->left = pt_right;
 
    else
        pt->parent->right = pt_right;
 
    pt_right->left = pt;
    pt->parent = pt_right;

}


// the helper rotateRight function[req by fixviolation function]
void rotateRight(NODE *root, NODE *pt){

	NODE *pt_left = pt->left;
 
    pt->left = pt_left->right;
 
    if (pt->left != NULL)
        pt->left->parent = pt;
 
    pt_left->parent = pt->parent;
 
    if (pt->parent == NULL)
        root = pt_left;
 
    else if (pt == pt->parent->left)
        pt->parent->left = pt_left;
 
    else
        pt->parent->right = pt_left;
 
    pt_left->right = pt;
    pt->parent = pt_left;
}

// The inorder tree Traversal 
void inorder(NODE *root){
	if(root != NULL){
		inorder(root->left);
		printf("%d : %c\t", root->data, root->color);
		inorder(root->right);
	}
}

// function responsible for swapping color[req by fixviolation function: recoloring property !!]
void swapcolor(NODE *parent_pt, NODE *grand_parent_pt){
	char temp_color;
	temp_color = parent_pt->color;
	parent_pt->color = grand_parent_pt->color;
	grand_parent_pt->color = temp_color;
}