#include <stdio.h>
#include <stdlib.h>
struct node *detect_loop(struct node *head);
struct node {
	int data;
	struct node * next;
};
int print_ll( struct node *temp )
{
	while( temp != NULL ){
		printf("%d ",temp -> data);
		temp = temp -> next;
	}
	printf("\n");	
}
struct node *create_ll(struct node *head, int size)
{
	struct node *new_node = NULL;
	struct node *temp = NULL;
	for( int i = 0; i < size; i++){
		new_node = ( struct node * ) malloc ( sizeof(struct node));
		printf("enter data for ll:\n");
		scanf("%d",&new_node -> data );
		new_node -> next = NULL;
		if( head == NULL ){
			head = new_node;
			temp = new_node;
		} else {
			temp -> next = new_node;
			temp = new_node;
		}
	}
	return head;
}
struct node *create_loop(struct node * head)
{
	struct node * temp = NULL;
	temp = head; 
	while(temp -> next != NULL){
		temp = temp -> next;
		if(temp -> next == NULL){
			temp -> next = head;
		}
	detect_loop(head);
	}
	return head;
}
struct node *detect_loop(struct node *head)
{
	struct node *temp = NULL;
	struct node *temp1 = NULL;
	temp = head;
	while(temp != NULL ) {
		temp1 = head;
		temp = temp-> next;
		while (temp1 != temp){
			temp1 = temp1 -> next;
			if( temp1 == temp){
				printf("loop detected\n");
				exit(EXIT_FAILURE);
			}			
		}
//		temp1 = head;
	}
	return head;
}
int main(void)
{
	int size;
	struct node *head = NULL;
	printf("enter size :");
	scanf("%d",&size);
	head = create_ll(head, size);
	head = create_loop(head);
	print_ll(head);
}
