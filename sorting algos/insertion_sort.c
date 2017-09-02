#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void insertion_sort(int *, int);
int main(){

	int arr[] ={34,2,0,9,1,78,45,3};

	insertion_sort(arr, sizeof(arr)/sizeof(arr[0]));
}

void insertion_sort(int *arr, int len){

   int i, key, j;
   for (i = 1; i < len; i++){
       key = arr[i];
       j = i-1;
 
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }


   for(i=0;i<len;i++)
   	printf("%d\t", arr[i]);
   printf("\n");
}