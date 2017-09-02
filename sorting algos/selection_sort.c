#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

void selection_sort(int*, int);
void print_arry(int *, int);
void swap(int *a, int *b);
int main(){

    int a1[] = {6, 8, 1, 0, 67, 45, 57, 32, 90};
    int a2[] ={4, 7, 0, 1, 12, 34, 56, 21, 98, 56, 43, 22};

	selection_sort(a1, sizeof(a1)/ sizeof(a1[0]));
	selection_sort(a2, sizeof(a2)/ sizeof(a2[0]));
}
 	 	
void selection_sort(int *arr, int len){

	int i, j, temp, min, flag =0;
	for(i=0; i < len-1; i++){
        min = i;
		for(j=i+1; j < len; j++)

			if(arr[j] < arr[min]){
                min = j;
            }
			 
				swap(&arr[min], &arr[i]);
			
		
	}

	for(i=0;i<len;i++)
		printf("%d\t", arr[i]);
	printf("\n");
}


void swap(int *xp, int *yp){

	int temp = *xp;
    *xp = *yp;
    *yp = temp;
}