#include<stdio.h>
int main(void)
{
	int n, i,search_element, low = 0 ,mid , high;
	printf( "enter no of elements u want \n" );
	scanf("%d", &n);
	int arr[n];
	printf("enter the array elements:\n");
	for( i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	printf("array elements are:\n");
	for( i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	printf("\nenter the elements u want to search:\n");
	scanf("%d", &search_element);
	high=n-1;	
	while( low < high ){
		mid=(high+low)/2;
		if( search_element == arr[mid] ){
			printf("%d\n",mid);
			break;
		}
		if(search_element > arr[mid]){
			low = mid + 1;
		}
		else{
			high = mid - 1;
//			mid = (low+high)/2;
		}
	}
	printf("%d is available in index %d\n", search_element, mid);
	return 0;
}
