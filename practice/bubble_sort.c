#include<stdio.h>
int bubble_sort(int *arr, int n);
int swap(int *var1, int *var2)
{
	int temp = *var1;
	*var1 = *var2;
	*var2 = temp;
}
int main(void)
{
	int n, *arr, i;
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
	bubble_sort(arr,n);
}
int bubble_sort(int *arr, int n)
{
	int flag;
	for(int i = 0; i < n-1; i++) {
		flag = 0;
		for(int j = 0; j < n - i - 1; j++){
			if( *(arr + j) > *(arr + j + 1)){
				swap((arr+j),(arr+j+1));
				flag = 1;
			}
		}
		if(flag == 0){
			break;
		}
	}
	printf("array elements are after sort:\n");
	for( int i = 0; i < n; i++){
		printf("%d ", *(arr+i));
	}
	printf("\n");
}
