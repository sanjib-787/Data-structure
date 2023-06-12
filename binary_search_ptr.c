#include"../hdr/header.h"
int *bubble_sort1(int *arr, int n);
int bin_search(int *arr, int n, int search_element);
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
	res = bin_search(arr, n, search_element);
	if( res == -1 ){
		printf("\nelement is out of array");
	} else {
		printf("\n%d is available in index %d\n", search_element, res);
	}
	return 0;
}
int bin_search( int *arr, int n, int search_element )
{
	int low = 0,high,mid;
	high=n-1;
	bubble_sort1(arr,n);
	while(low <= high){
		mid = (low + high) / 2;
		if(search_element == *(arr+mid)){
		//	printf("%d\n",mid);
			return mid;
		}
		if( search_element > *(arr + mid)){
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return -1;
}
int *bubble_sort1(int *arr, int n)
{
	int i, j, flag;
	for( i = 0; i < n-1; i++ ) {
		flag = 0;
		for( j = 0; j < n-1-i; j++) {
			if( *(arr+j) > *(arr + j +1)){
				swap(arr+j,arr+j+1);
				flag = 1;
			}
		}
		if( flag == 0){
			break;
		}
	}
	printf("\nafter sorting\n");
	for( i = 0; i < n; i++){
		printf("%d ", *(arr+i));
	}
	return arr;
}
