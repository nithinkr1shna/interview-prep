// A toy hash implementation : concept of separate chaining..
// hash words with meanings.
// uses a hash function

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HASH_TABLE_SIZE 100
#define HASH_KEY 25

struct word_obj{

	int hash_value;
	char *word;
	char *meaning;
	struct word_obj *next;
};

typedef struct word_obj word_t;

union fun_return{

	word_t *word;
	char *return_message;
}u;

struct return_of_search_fun{
	char *type;
	union fun_return u;
};

typedef struct return_of_search_fun search_return_t;




int hash(char *, int );
void init(word_t **);
void insert(word_t **, char *, char *);
search_return_t update(word_t **, char *, char *);
void printhash(word_t **); 
word_t *newNode(char *, char *, int );
search_return_t search(word_t **, char *);

void printresult(search_return_t );


// sample driver code
int main(){
	word_t *words[HASH_TABLE_SIZE];

    search_return_t result1, result2, update_result;

    init(words);
    insert(words, "baby", "a very young child.");
	insert(words, "concatenation", "a series of interconnected or interdependent things or events.");
	insert(words, "sinecure","an office or position requiring little or no work, especially one yielding profitable returns.");
	insert(words, "antinome","something that is contradictory or opposite to another; a logical contradiction.");
	insert(words, "vamoose","Slang. to leave hurriedly or quickly; decamp.");
	insert(words, "gramarye","occult learning; magic");
	insert(words, "babassu oil", "a yellow oil expressed or extracted from babassu nuts, used chiefly in the manufacture of soaps and cosmetics and as a cooking oil.");
	insert(words, "babble", "to utter sounds or words imperfectly, indistinctly, or without meaning.");
	 
	// Initially displaying the words and meaning
	printhash(words);

    // searching for word babble in the dic
	result1 = search(words, "babble");
	printresult(result1);

    // searching for word gramarye
	result2 = search(words, "gramarye");
	printresult(result2);
     
    // trying to update an existing word
    update_result = update(words, "babble", "new meaning");
    printresult(update_result);

    
    // displaying the dic after updation
    //printhash(words);

    

}	




// A simple hash function
int hash(char *word, int key){

	char *p = word;
	int hash_val = 0;
	for(;*p != '\0'; p++){
		hash_val += (int)*p;
	}
	hash_val += key;
   
    return hash_val % HASH_TABLE_SIZE;
}


// a utility used to print the result 
void printresult(search_return_t result){
	printf("\nRESULT \n");
	if(strcmp(result.type, "string") == 0){
		printf("%s\n", result.u.return_message);
	}else{
		printf("%20s ::%s\n", result.u.word->word, result.u.word->meaning);
	}
}


// search for a word if word found word along with meaning is returned else no entry(using union nested struct)
search_return_t search(word_t **words, char *word){

	search_return_t return_val;

	int hash_val = hash(word, HASH_KEY);
	//printf("hash %d", hash_val);
	if(words[hash_val] == NULL){
		return_val.type = "string";
		return_val.u.return_message = "Entry not found\n";

	}else{
		word_t *current = words[hash_val];
		for(;current != NULL; current = current->next)
			if(strcmp(word, current->word) == 0){
				return_val.type = "word";
				return_val.u.word = current;

			}
	
	}
	return return_val;

}




search_return_t update(word_t **words, char *word, char *meaning){

	search_return_t result = search(words, word);
	search_return_t return_val;
	if(strcmp(result.type, "string") == 0){
		return_val.type ="string";
		return_val.u.return_message = "Entry Not Found";
	}else{
		result.u.word->meaning = meaning;
		return_val.type ="word";
		return_val.u.word = result.u.word;
	}
    
    
	return return_val;
}


// Utility to insert word and its meanig 
void insert(word_t **words, char *word, char *meaning){
	
	int hash_val =0;
	hash_val=  hash(word, HASH_KEY);
	word_t *new = newNode(word, meaning, hash_val);
	if(words[hash_val] == NULL)
		words[hash_val] = new;
	else{
		word_t *current = words[hash_val];
		for(;current->next != NULL; current = current->next)
			;
		current->next = new;
	}

}




// initialize all the hash index to NULL
void init(word_t **word){
	int i;
	for(i=0; i<HASH_TABLE_SIZE; i++)
		word[i] = NULL;
}


// utility used to print the whole ds
void printhash(word_t **words){
	printf("\n\n----------------------WORDS AND MEANING-----------------\n\n");
	int i;
	for(i=0; i< HASH_TABLE_SIZE ;i++)
		if(words[i] != NULL){
			word_t *current = words[i];
			for(;current != NULL; current = current->next)
				printf("%d) word :%20s\t:: %s\n",current->hash_value, current->word, current->meaning);
		}

	printf("\n--------------------------------------------------------\n\n");
	
}

// utility that creates new object with word and its meaning.
word_t *newNode(char *word, char *meaning, int hash_val){
	word_t *new = (word_t*)malloc(sizeof(word_t));
	new->hash_value = hash_val;
	new->word = word;
	new->meaning = meaning;
	new->next = NULL;

	return new;
}
