#include"../hdr/header.h"
#define N 10
int enqueue( int queue[] ,int * , int *, int );
int display( int queue[], int * ,int *);
int dequeue( int *, int *);
int main(void)
{
	int choice, queue[N], size, front = -1, rear = -1;
	printf("enter size of queue less then 10:\n");
	scanf( "%d", &size );
	while(1){
		printf("1:Enqueue\n2:Dequeue\n3:display\n4:exit\n");
		printf("enter ur choice:\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				enqueue ( queue , &rear, &front, size);
				break;
			case 2:
				dequeue ( &front, &rear );
				break;
			case 3:
				display ( queue, &rear, &front);
				break;
			case 4:
				exit(EXIT_SUCCESS);
			default :
				printf("wrong choice\n");
		}
	}
}
int enqueue(int queue[], int *rptr, int *fptr, int size )
{
	int val;
	if ( *rptr == size -1){
		printf("Queue is full\n");
	} else {
		if( *fptr == -1){
			*fptr = 0;
		}
		printf("enter value for queue:\n");
		scanf("%d",&val);
		(*rptr)++;
		queue[*rptr] = val;	
	}
	return *fptr;
}
int dequeue(int *fptr, int *rptr)
{
	if( *fptr == -1){
		printf("Queue is empty\n");
	} else {
		(*fptr)++;
		if( *fptr > *rptr ) {
			*fptr = *rptr = -1;
		}
	}
}
int display( int queue[],int *rptr, int *fptr )
{
	printf( "\nelements are \n");
	for(int i = *fptr; i <= *rptr; i++){
		printf( "%d ", queue[i]);
	}
	printf("\n");
}
