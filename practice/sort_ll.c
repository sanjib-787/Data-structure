#include <stdio.h>
#include <stdlib.h>
struct node *detect_loop(struct node *head);
struct node {
	int data;
	struct node * next;
};
void swap(struct node *a, struct node *b)
{
	int temp = a -> data;
	a -> data = b -> data;
	b -> data = temp;
}
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
struct node *sort_ll(struct node *head)
{
	struct node *temp = NULL;
	struct node *temp1 = NULL;
	for(temp = head; temp != NULL; temp = temp -> next) {
		for(temp1 = temp->next; temp1 != NULL; temp1 = temp1 -> next) {
			if(temp->data > temp1->data){
				swap(temp, temp1);
			}
		}
	}
	return head;
	
}
int main(void)
{
	int size, data;
	struct node *head = NULL;
	printf("enter size :");
	scanf("%d",&size);
	head = create_ll(head, size);
	head = sort_ll(head);
	print_ll(head);
	return 0;	
}
