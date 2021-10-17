/*
 ============================================================================
 Name        : LinearSearch(c).c
 Author      : Sandesh Yadav
 Version     :
 Copyright   : Your copyright notice
 Description : Linear Search Algorithm in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int LinearSearch(int *arr,int num_ele, int srch);

int main(){
	int ele, e, num;
	printf("Enter the number of elements in the array: \n");
	scanf("%d",&ele);
	int array[ele];
	for (int i = 0; i < ele; i++){
		printf("Enter the element at %d position: \n",i);
		scanf("%d",&e);
		array[i] = e;
	}
	printf("Enter the element you want to search for: \n");
	scanf("%d",&num);
	int res = LinearSearch(array, ele, num);
	if (res < 0){
		printf("Sorry!!... Number not found in the array");
	}
	else{
		printf("The element found  at index %d and position  %d",res,res + 1);
	}
}

int LinearSearch(int *arr, int num_ele, int srch){
	for (int j = 0; j < num_ele; j++){
		if (arr[j] == srch){
			return j;
			break;
		}
}

