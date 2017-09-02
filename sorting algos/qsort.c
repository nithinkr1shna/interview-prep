#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(int *a, int *b);
void q_sort(int *, int , int );

int main(){

    int i, len;
	int arry[] = {3, 6,7 ,89,23,1, 8, 76, 67};
	len = sizeof(arry)/sizeof(arry[0]);
	q_sort(arry, 0,len);
	for(i=0;i<len;i++)
		printf("%d\t", arry[i]);
}


void q_sort(int *arr, int r, int l){

	int pivot = arr[l-1];
	printf("pivot  %d\n",pivot);
	int i =-1, j, u;
	j = 0;
	if(r < l){

	while(j < l){

		if(arr[j] <= pivot){
			i++;
			swap(&arr[i], &arr[j]);
		}
		j++;
	}

    q_sort(arr, r, i);
    q_sort(arr,i+1, l);
}



}

void swap(int *xp, int *yp){

	int temp = *xp;
    *xp = *yp;
    *yp = temp;
}