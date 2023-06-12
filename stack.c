#include"../hdr/header.h"
#define N 10
int push( int stack[] ,int top, int size);
int display( int stack[], int top );
int pop( int top);
int main(void)
{
	int choice, stack[N], size, top = -1;
	printf("enter size:\n");
	scanf( "%d", &size );
	while(1){
		printf("1:push\n2:pop\n3:display\n");
		printf("enter ur choice:\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				top = push ( stack , top, size);
				break;
			case 2:
				top = pop ( top );
				break;
			case 3:
				display ( stack, top );
				break;
			default :
				printf("wrong choice\n");
				exit(EXIT_SUCCESS);
		}
	}
}
int push( int stack[] ,int top, int size)
{
	if( top == size - 1) {
		printf( " stack OverFlow \n" );
	}
	else {
		int val;
		printf( "enter the element: \n");
		scanf( "%d", &val );
		top++;
		stack[ top ] =val;
	}
	return top;
}
int pop( int top)
{
	if ( top == -1 ){
		printf( "stack underflow \n");
	}
	else {
		printf("element removed from stack.");
		top--;
	}
	return top;
}
int display( int stack[],int top )
{
	printf( "elements are ");
	for(int i=0;i<=top;i++){
		printf( "%d ", stack[i] );
	}
	printf("\n");
}

