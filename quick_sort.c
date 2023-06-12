#include"../hdr/header.h"
int partion(int *arr, int left, int right);
int quick_sort(int *arr, int left, int right); 
int main(void) 
{
	int n, *arr, i, left, right;
	printf( "enter no of elements u want \n" );
	scanf("%d", &n);
	left = 0;
	right = n-1;
	printf("enter the array elements:\n");
	for( i = 0; i < n; i++){
		scanf("%d", arr+i);
	}
	printf("array elements are:\n");
	for( i = 0; i < n; i++){
		printf("%d ", *(arr+i));
	}
	quick_sort( arr, left, right );
	printf("\n");
	printf("after sorting \n");
	for( i = 0; i < n; i++){
		printf("%d ", *(arr+i));
	}
}
int partion(int *arr, int left, int right)
{
	int pivot, start, end;
	pivot = *(arr+left);
	start = left;
	end = right;
	while ( start < end){
		while ( *( arr + start ) < pivot ) {
			start++;
		}
		while ( *( arr + end ) > pivot ) {
			end--;
		}
		if( start < end ) {
			swap( arr + start , arr + end );
		} else {
			swap( arr + end , &pivot );

		}
	}
//	swap( arr + left, arr + right );
	return end;
}
int quick_sort(int *arr, int left, int right) 
{
	int loc;
	if( left < right )
	{
		loc = partion( arr, left, right);
		quick_sort( arr, left, loc-1);
		quick_sort( arr, loc+1, right);
	}
}
