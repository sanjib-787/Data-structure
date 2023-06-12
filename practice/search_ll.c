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
int search_data(struct node *head, int data)
{
	struct node *temp = NULL;
	int count = 0;
	temp = head;
	while(temp != NULL){
		count++;
		if(data == temp -> data){
			return count;
		}else{
			temp = temp -> next;
		}
	}
}
int main(void)
{
	int size, data;
	struct node *head = NULL;
	printf("enter size :");
	scanf("%d",&size);
	head = create_ll(head, size);
	print_ll(head);
	printf("enter data from ll:");
	scanf("%d",&data);
	printf("data available in %d node",search_data(head, data));
}
