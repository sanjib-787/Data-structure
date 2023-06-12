#include"../hdr/header.h"
int merge_sort(int n, int arr[],int left, int right);
int merge( int n, int arr[], int left, int mid, int right );
int main(void) 
{
	int size, i, left, right;
	printf( "enter no of elements u want \n" );
	scanf("%d", &size);
	int arr[size];
	left = 0;
	right = size-1;
	printf("enter the array elements:\n");
	for( i = 0; i < size; i++){
		scanf("%d", &arr[i]);
	}
	printf("array elements are: \n");
	for( i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
	merge_sort(size, arr, left, right );
	printf("\n");
	printf("after sorting \n");
	for( i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
}
int merge_sort(int n, int arr[], int left, int right)
{
	int mid;
	if( left < right ) {
		mid = ( left + right ) / 2;
		merge_sort(n, arr, left, mid );
		merge_sort(n, arr, mid + 1, right );
		merge(n, arr, left, mid, right );
	}
	return 0;
}
int merge(int n,  int arr[], int left, int mid, int right )
{
	int i, j, k, temp[n];
	i=left;
	j=mid+1;
	k=left;
	while( i <= mid && j <= right ){
		if( arr[i] <= arr[j] ) {
			temp[k] = arr[i];
			i++;
		} else {
			temp[k] = arr[j];
			j++;
		}
		k++;
	}
	if(i > mid){
		while ( j <= right ) {
			temp[k]=arr[j];
			j++;
			k++;
		}
	} else {
		while ( i <= mid ){
			temp[k] = arr[i];
			i++;
			k++;
		}
	}
	for( k = left; k <= right; k++){
		arr[k]=temp[k];
	}
	return 0;
}
