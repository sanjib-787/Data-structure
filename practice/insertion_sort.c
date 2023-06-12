#include<stdio.h>
int insertion_sort(int *, int);
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
	printf("\n");
	insertion_sort(arr,n);
}
int insertion_sort(int *arr, int n)
{
	int temp, i, j;
	for(i = 1; i < n; i++){
		temp = *(arr+i);
		for(j = i - 1; j >= 0 && *(arr+j) > temp; j--) {
			*(arr+j+1) =*(arr + j);
		}
		*(arr+j+1) = temp;
	}
	printf("sorted array:\n");
	for(i = 0; i < n; i++) {
		printf("%d ",*(arr+i));
	}
	printf("\n");
}
