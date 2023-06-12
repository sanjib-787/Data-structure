#include"../hdr/header.h"
int main(void)
{
	int n, *arr, i, j, flag;
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
	for( i = 0; i < n-1; i++ ) {
		flag = 0;
		for( j = 0; j < n-1-i; j++) {
			if( *(arr+j) < *(arr + j +1)){
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
	printf("\nlargest two number is %d %d\n",*(arr),*(arr+1));
}
