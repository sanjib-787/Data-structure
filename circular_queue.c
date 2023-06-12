#include"../hdr/header.h"
#define N 10
int circular_enqueue( int queue[] ,int * , int *, int );
int circular_display( int queue[], int * ,int *, int);
int circular_dequeue( int *, int *);
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
				circular_enqueue ( queue , &rear, &front, size);
				break;
			case 2:
				//dequeue ( &front, &rear );
				break;
			case 3:
				circular_display ( queue, &rear, &front, size);
				exit(EXIT_SUCCESS);
				break;
			case 4:
				exit(EXIT_SUCCESS);
			default :
				printf("wrong choice\n");
		}
	}
}
int circular_enqueue( int queue[] ,int *rear , int *front, int size)
{
	int data;
	printf("enter data \n");
	scanf("%d", &size);
	if( (*front) == -1 && (*rear) == -1 ) {
		*front = 0;
		*rear = 0;
		queue[*rear] = data ;
	} else if ( (((*rear) + 1) % size) == (*front) ) {
		printf("queue is full");
	} else {
		*rear = ((*rear) + 1) % size;
		queue[*rear] = data;
	}
}
int circular_dequeue(int *front, int *rear)
{
	if()
}
int circular_display( int queue[], int *rear ,int *front, int size)
{
	int i = (*front);
	printf("i %d\n",i);
	printf("rear %d\n",*rear);
	if( *front == -1 && * rear == -1){
		printf("queue is empty \n");
	} else {
		printf("queue is \n");
		while( i != (*rear) ){
			printf("%d ",queue[i]);
			i = (i + 1) % size;
			printf("i is %d\n",i);
		}
	}
}










