#include <stdio.h>
#include <string.h>
#include <stdlib.h>
                                   // a -------z
#define SIZE 26         
#define ASCII_a 97          // 97 ---- 122

struct node{
	char *word;
	char *meaning;
	struct node *next;
	
};


typedef struct node NODE;

void insert(NODE **, char *, char *);
int first_letter(char *);
NODE *newNode(char *, char *);
void init(NODE **);
void printds(NODE **);
char *getmeaning(NODE **, char *);
char *update(NODE **, char *, char *);

NODE **ui(NODE **words);

int main(){

    NODE *words[SIZE];
    init(words);
    insert(words, "ant", "insect");
    insert(words, "cat", "an animal");
    insert(words, "zebra", "another animal");
    insert(words, "centipede", "insect");
    printds(words);
    printf("%s\n",getmeaning(words, "zebra"));
    printf("%s\n",getmeaning(words, "maniac"));
    printf("%s\n",update(words, "donkey", "another animal"));
    printf("%s\n",update(words, "zebra", "a weird animal"));
  
    printf("\n");
    printds(words);

    


	return 0;
}

void insert(NODE **words, char *word, char *meaning){
	int index = first_letter(word);
	NODE *w = newNode(word, meaning);
	if(words[index] == 0){
		words[index] = w;
	}
	else{
		NODE *current = words[index];
		for(;current->next != NULL; current = current->next)
			;
		current->next = w;
	}


}

char *getmeaning(NODE **words, char *word){
	int index = first_letter(word);
	if(words[index] == 0){

		return "Entry not found";
	}
	NODE *current = words[index];
	for(;current != NULL; current = current->next)
		if(strcmp(word, current->word) ==0){
			return current->meaning;
		}
	return "Entry not found";

	
}


char *update(NODE **words, char *word, char *new_meaning){

	if(strcmp(getmeaning(words, word), "Entry not found") == 0){
		return "Cant update, word not found";
	}else{
		int index = first_letter(word);
		NODE *current = words[index];
		for(;current != NULL; current = current->next)
			if(strcmp(word, current->word) == 0){
				current->meaning = new_meaning;
			}
		return "Successfully updated";
	}


}

void printds(NODE **words){
	int i;
	for(i=0;i<SIZE;i++){
		if(words[i] != 0){
			NODE *current = words[i];
			for(;current != NULL; current = current->next)
				printf("%15s: %s\n", current->word, current->meaning);
		}


	}
}

void init(NODE **words){
	int i;
	for(i= 0; i <SIZE; i++)
		words[i] =0;
}





int first_letter(char *word){
	return (int)*word - ASCII_a;
}


NODE *newNode(char *word, char *meaning){
	NODE *new = (NODE*)malloc(sizeof(NODE));
	new->word = word;
	new->meaning = meaning;
	new->next = NULL;

	return new;
}
