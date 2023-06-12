#include<stdio.h>
int linear_search(int *arr, int n, int search_element);
int main(void)
{
	int n, *arr, i, res,search_element;
	printf( "enter no of elements u want \n" );
	scanf("%d", &n);
	printf("enter the array elements:\n");
	for( i = 0; i < n; i++){
		scanf("%d", arr+i);
	}
	printf("array elements are:\n");
	for( i = 0; i < n; i++){
		printf("%d ", *(arr+i));
	}
	printf("\nenter the elements u want to search:\n");
	scanf("%d", &search_element);
	res = linear_search(arr, n, search_element);
	printf("%d is available in index %d\n", search_element, res);
	return 0;
}
int linear_search(int *arr, int n, int search_element)
{
	int i;
	for( i = 0; i < n; i++){
		if( *(arr+i) == search_element){
			return i;
		}
	}
}
