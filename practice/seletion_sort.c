#include<stdio.h>
int selection_sort(int *arr, int n);
int swap(int *var1, int *var2)
{
	int temp = *var1;
	*var1 = *var2;
	*var2 = temp;
}
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
	selection_sort(arr,n);

}
int selection_sort(int *arr, int n)
{
	int i, j, min;
	for(int i = 0; i < n-1; i++) {
		min = i;
		for(int j = i+1; j < n; j++) {
			if(*(arr+j) < *(arr + min)) {
				min = j;
			}
		}
		if(min != i){
			swap(arr+min,arr+i);
		}
	}
	printf("after sorting:\n");
	for(int i = 0; i < n; i++){
		printf("%d ",*(arr+i));
	}
	printf("\n");
}
