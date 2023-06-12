#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
int push(int arr[], int size, int top);
int pop(int top);
int display(int arr[], int top);
int main(void)
{
	int stack[SIZE], choice, top = -1, size;
	printf("enter size of stack: ");
	scanf("%d",&size);
	while(1){
		printf("enter your choice:\n");
		printf("1.push\n2.pop\n3.display\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				top = push(stack, size, top);
				break;
			case 2:
				top = pop(top);
				break;
			case 3:
				display(stack, top);
				break;
			default:
				exit(EXIT_FAILURE);
		}
	}
	
}
int push(int arr[], int size, int top)
{
	int n;
	if(top == size-1) {
		printf("stack overflow\n");
	} else {
		printf("enter number: ");
		scanf("%d",&n);
		top++;
		arr[top] = n;
	}
	return top;
}
int pop(int top)
{
	if(top == -1) {
		printf("stack is empty.\n");
	} else {
		top--;
		printf("one item is deleted.\n");
	}
	return top;
}
int display(int arr[], int top)
{
	for(int i = 0; i <= top; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
