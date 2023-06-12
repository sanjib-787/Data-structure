#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 20
int linear_search_str(int n, char *arr[n], char *search_element);
int main(void)
{
	int n, i, res;
	printf( "enter no of elements u want \n" );
	scanf("%d", &n);
	char *arr[n], *search_element;
	printf("enter the array elements:\n");
	for( i = 0; i < n; i++){
		arr[i]=(char *)malloc(sizeof(char)*SIZE);
		scanf("%s", arr[i]);
	}
	printf("array elements are:\n");
	for( i = 0; i < n; i++){
		printf("%s ", arr[i]);
	}
	printf("\nenter the elements u want to search:\n");
	scanf("%s", search_element);
	res = linear_search_str(n, arr, search_element);
	if(res > 0){
		printf("%s is available in index %d\n", search_element, res);
	} else {
		printf( "%s is not available in this array\n", search_element );
	}
	return 0;
}
int linear_search_str(int n, char *arr[n], char *search_element)
{
	int temp;
	for(int i = 0; i < n; i++){
		temp = strcmp(arr[i],search_element);
		if( temp == 0 ){
	//		printf("res available in %d\n",i);
			return i;
		}
	}
	return -1;
}
