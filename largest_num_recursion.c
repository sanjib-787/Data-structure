#include"../hdr/header.h"
int large(int *arr, int index, int temp);
int main(void)
{
	int n, *arr, i, temp, largest;
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
	if( n == 0) {
		printf("empty list\n");
	}
	else {
		temp = *arr;
		largest = large( arr, n-1, temp );
		printf("\nlargest number is %d\n", largest);
	}
}
int large(int *arr, int index, int temp)
{
	if( index == 0){
		return temp;
	}
	if ( index > 0) {
		if ( *( arr + index ) > temp ){
			temp = *( arr + index );
		}
		return large( arr, index - 1, temp);
	}
}
