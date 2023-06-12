#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
int print_ll( struct node *temp )
{
	while( temp != NULL ){
		printf("%d ",temp -> data);
		temp = temp -> next;
	}
	printf("\n");	
}
int print_node( struct node *temp )
{
	while( temp != NULL ){
		printf("%p ",temp -> next);
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
		printf("enter data for node[%d]:\n",i);
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
struct node *swap_node(struct node *head)
{
	struct node *temp = NULL;
	struct node *temp1 = NULL;
	struct node *temp2 = NULL;
	struct node *prev1 = NULL;
	struct node *prev2 = NULL;
	struct node *var1 = NULL;
	struct node *var2 = NULL;
	int key1, key2;
	temp1 = head;
	temp2 = head;
	prev1 = head;
	prev2 = head;
	printf("enter key1:\n");
	scanf("%d",&key1);
	printf("enter key2:\n");
	scanf("%d",&key2);
	while(temp1 != NULL) {
		prev1 = temp1;
		if(temp1 -> data == key1){
			break;
		}
		temp1 = temp1 -> next;
	}
	while(temp2 != NULL) {
		prev2 = temp2;
		if(temp2 -> data == key2) {
			break;
		}
		temp2 = temp2 -> next;
	}
	print_node(head);
	if(temp1 == head){
				
	}else{
		var1 = temp1 -> next;
		var2 = temp2 -> next;
		prev1 -> next = temp2;
		prev2 -> next = temp1;
		temp = temp1;
		temp1 = temp2;
		temp2 = temp;
		temp1 -> next = var1;
		temp2 -> next = var2;
		print_node(head);
	}
	print_ll(head);

}
int main(void)
{
	int size, choice;
	struct node *head = NULL;
	printf("enter size:\n");
	scanf("%d",&size);
	head = create_ll( head, size);
	print_ll(head);
	swap_node(head);
}












