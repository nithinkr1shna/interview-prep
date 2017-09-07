// Word dictionary with the help of BST
//OPerations supported:
//  1. inserting a word and a meaning
//  2. searching for a paticular word.
//  3. displaying the word in increasing order.



#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
	char *word;
	char *meaning;
	struct node *left;
	struct node *right;
};

typedef struct node NODE;


NODE *insert(NODE *, char *, char *);
NODE *newNode(char *, char *);
void inorder(NODE *);
void preorder(NODE *);
void postorder(NODE *);	
NODE* search(NODE *, char *);

int main(){

	NODE *root = NULL;
	NODE *node;
	root = insert(root,"cat", "an animal");
	insert(root, "dog", "bdwuk");
	insert(root, "horse", "another animal");
	insert(root, "duw", "gduiw");
	insert(root, "gug", "gyeid");
	insert(root, "dwdw", "gdyeidge");
	inorder(root);
	//printf("\n");
	//preorder(root);
	//printf("\n");
	//postorder(root);

	node = search(root, "cat");
	printf("%s: %s", node->word, node->meaning);
}



// Insert a word and its meaning according to the lexicographical order of the word.
NODE *insert(NODE *root, char *word, char *meaning){

	if(root == NULL)
		return newNode(word, meaning);

	if(strcmp(word, root->word) < 0){
		//printf("word is greater\n");
		root->left = insert(root->left, word, meaning);
	}
	if(strcmp(word, root->word) > 0){
		//printf("word is lesser\n");
		root->right = insert(root->right, word, meaning);
	}
	return root;



}

// returns a new node with word and meanig, left and right child pointing to NULL
NODE *newNode(char *word, char *meaning){

	NODE *new = (NODE*)malloc(sizeof(NODE));
	new->word = word;
	new->meaning = meaning;
	new->left = new->right = NULL;

	return new;
}

// displays the BST inorder 
void inorder(NODE *root){

	if(root != NULL){

		inorder(root->left);
		printf("%s : %s\n", root->word, root->meaning);
		inorder(root->right);
	}
}

// displays the BST in preorder
void preorder(NODE *root){
	if(root != NULL){
		preorder(root->left);
		preorder(root->right);
		printf("%s :%s\n",root->word, root->meaning );
	}
}

// displays the BST in postorder
void postorder(NODE *root){
	if(root != NULL){
		printf(" %s: %s\n",root->word, root->meaning );
		postorder(root->left);
		postorder(root->right);
	}
}

//search for a word in BST
NODE *search(NODE *root, char *word){

	if(root == NULL || strcmp(word, root->word) == 0)
		return root;
	if(strcmp(word, root->word) > 0)
		return search(root->right, word);
	if(strcmp(word, root->word) <0)
		return search(root->left, word);

}