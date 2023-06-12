#include"../../hdr/header.h"
#define N 10
int push1( int stack[] ,int top1, int size, int top2);
int push2(int stack[], int top2, int size, int top1);
int pop1( int top1);
int pop2( int top2, int size);
int display1( int stack[], int top1 );
int display2( int stack[], int top2, int size );
int main(void)
{
	int choice, stack[N], size, top1 = -1, top2;
	printf("enter size:\n");
	scanf( "%d", &size );
	top2 = size;

	while(1){
		printf("1:push1\t2:push2\t3:pop1\t4:pop2\t5:display1\t6:display2\n");
		printf("enter ur choice:\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				top1 = push1 ( stack ,top1, size, top2);
				break;
			case 2:
				top2 = push2 (stack, top2, size, top1);
				break;
			case 3:
				top1 = pop1(top1);
				break;
			case 4:
				top2 = pop2(top2, size);
				break;
			case 5:
				display1 ( stack, top1 );
				break;
			case 6:
				display2 ( stack,top2,size);
				break;
			default :
				printf("wrong choice\n");
				exit(EXIT_SUCCESS);
		}
	}
}
int push1( int stack[] ,int top1, int size, int top2)
{
	if( top1 < top2 - 1) {
		int val;
		printf( "enter the element: \n");
		scanf( "%d", &val );
		top1++;
		stack[ top1 ] =val;
	}
	else {
		printf( " stack OverFlow \n" );
	}
	return top1;
}
int push2(int stack[], int top2, int size, int top1)
{
	if (top1 < top2 -1){
		int val;
		printf( "enter the element: \n");
		scanf( "%d", &val );
		top2--;
		stack[ top2 ] =val;
	} else {
		printf("stack overflow\n");
	}
	return top2;
}
int pop1( int top1)
{
	if ( top1 == -1 ){
		printf( "stack underflow \n");
	}
	else {
		printf("element removed from stack.\n");
		top1--;
	}
	return top1;
}
int pop2(int top2, int size)
{
	if(top2 == size){
		printf("stack is empty\n");
	} else {
		printf("deleted element is\n");
		top2 = ++top2;
	}
	return top2;
}
int display1( int stack[],int top1 )
{
	printf( "elements in stack1\n");
	for(int i = top1; i >= 0; i--){
		printf( "%d ", stack[i] );
	}
	printf("\n");
}
int display2(int stack[], int top2, int size)
{
	printf( "elements in stack2 \n");
	for(int i = top2; i < size; i++){
		printf( "%d ", stack[i] );
	}
	printf("\n");
	
}
