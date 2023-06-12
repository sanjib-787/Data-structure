#include"../hdr/header.h"
struct Node{
	int data;
	struct Node *next;
};
int print_ll( struct Node *temp )
{
	while( temp != NULL ){
		printf("%d ",temp -> data);
		temp = temp -> next;
	}
	
}
struct Node *create_ll(struct Node *head, struct Node *temp, int size)
{
	struct Node *new_node = NULL;
	for( int i = 0; i < size; i++){
		new_node = ( struct Node * ) malloc ( sizeof(struct Node *));
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
	temp = head;
	return temp;
}
struct Node *delete_begning(struct Node *head )
{
	if ( head == NULL ){
		printf("list is empty\n");
	} else {
		struct Node *temp = NULL;
		temp = head;
		head = head -> next;
		free( temp );
	}
	return head;
}
struct Node *delete_end(struct Node *head )
{
	struct Node *temp = NULL;
	struct Node *temp1 = NULL;
	if ( head == NULL ){
		printf("list is empty\n");
	} else {
		temp = head;
		temp1 = head;
		while( temp -> next != NULL){
			temp1 = temp;
			temp = temp -> next;
		}
			temp1 -> next = NULL;
			free( temp );
	}
	return head;
}
struct Node *delete_position( struct Node *head)
{
	struct Node *temp = NULL;
	struct Node *temp1 = NULL;
	int i = 1, pos;
	temp = head;
	if ( head == NULL ){
		printf("list is empty\n");
	} else {
		printf("Enter the position \n");
		scanf("%d", &pos);
		while( i < pos - 1 ) {
			temp = temp -> next;
			i++;
		}
		temp1 = temp -> next;
		temp -> next = temp1 -> next;
		free( temp1 );
	}
	return head;
}
struct Node *delete_before_position( struct Node *head)
{
	struct Node *temp = NULL;
	struct Node *temp1 = NULL;
	int i = 1, pos;
	temp = head;
	if ( head == NULL ){
		printf("list is empty\n");
	} else {
		printf("Enter the position \n");
		scanf("%d", &pos);
		while( i < pos - 2 ) {
			temp = temp -> next;
			i++;
		}
		temp1 = temp -> next;
		temp -> next = temp1 -> next;
		free( temp1 );
	}
	return head;
}
struct Node *delete_after_position( struct Node *head)
{
	struct Node *temp = NULL;
	struct Node *temp1 = NULL;
	int i = 1, pos;
	temp = head;
	if ( head == NULL ){
		printf("list is empty\n");
	} else {
		printf("Enter the position \n");
		scanf("%d", &pos);
		while( i < pos ) {
			temp = temp -> next;
			i++;
		}
		temp1 = temp -> next;
		temp -> next = temp1 -> next;
		free( temp1 );
	}
	return head;
}

struct Node *delete_before_number( struct Node *head)
{
	struct Node *temp = NULL;
	struct Node *temp1 = NULL;
	int i = 1, pos, num;
	printf("enter a number:\n");
	scanf("%d", &num);
	temp = head;
	while( temp -> next != NULL) {
		temp = temp -> next;
		if( num == temp -> data){
			printf("%d\n", i);
			pos = i;
			break;
		}
		i++;
	}
	temp = head;
	if ( head == NULL ){
		printf("list is empty\n");
	} else {
		while( i < pos - 1 ) {
			temp = temp -> next;
			i++;
		}
		temp1 = temp -> next;
		temp -> next = temp1 -> next;
		free( temp1 );
	}
	return head;
}
struct Node *delete_after_number( struct Node *head)
{
	struct Node *temp = NULL;
	struct Node *temp1 = NULL;
	int i = 1, pos, num;
	printf("enter a number:\n");
	scanf("%d", &num);
	temp = head;
	while( temp -> next != NULL) {
		temp = temp -> next;
		if( num == temp -> data){
			printf("%d\n", i);
			pos = i;
			break;
		}
		i++;
	}
	temp = head;
	if ( head == NULL ){
		printf("list is empty\n");
	} else {
		while( i < pos + 1 ) {
			temp = temp -> next;
			i++;
		}
		temp1 = temp -> next;
		temp -> next = temp1 -> next;
		free( temp1 );
	}
	return head;
}
struct Node *delete_mid( struct Node *head, int *newsize)
{
	struct Node *temp = NULL;
	struct Node *temp1 = NULL;
	int i = 1, pos, num;
	temp = head;
	pos = (*newsize) / 2;
	if ( head == NULL ){
		printf("list is empty\n");
	} else {
		while( i < pos ) {
			temp = temp -> next;
			i++;
		}
		temp1 = temp -> next;
		temp -> next = temp1 -> next;
		free( temp1 );
	}
	return head;
}
struct Node *delete_penultimate( struct Node *head, int *newsize)
{
	struct Node *temp = NULL;
	struct Node *temp1 = NULL;
	int i = 1, pos, num;
	temp = head;
	pos = *newsize - 1;
	if ( head == NULL ){
		printf("list is empty\n");
	} else {
		while( i < pos - 1 ) {
			temp = temp -> next;
			i++;
		}
		temp1 = temp -> next;
		temp -> next = temp1 -> next;
		free( temp1 );
	}
	return head;
}



int main(void)
{
	int size, choice;
	struct Node *head = NULL;
	struct Node *temp = NULL;
	struct Node *new_node = NULL;
	printf("enter size:\n");
	scanf("%d",&size);
	head = create_ll( head, temp, size);
	while(1){
		printf("1. Delete at the beginning\n2. Delete at the end\n3. Delete at a given position\n4. Delete before a given position\n5. Delete after a given position\n6. Delete before a given number\n7. Delete after a given number\n8. Delete at the middle\n9. Delete at penultimate node\n10. Print Linked list\n");
		printf("enter ur choice:\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				head = delete_begning( head );
				break;
			case 2:
				head = delete_end( head );
				break;
			case 3:
				head = delete_position( head );
				break;
			case 4:
				head = delete_before_position( head );
				break;
			case 5:
				head = delete_after_position( head );
				break;
			case 6:
				head = delete_before_number( head );
				break;
			case 7:
				head = delete_after_number( head );
				break;
			case 8:
				head = delete_mid( head, &size );
				break;
			case 9:
				head = delete_penultimate(head, &size);
				break;
			case 10:
				print_ll( head );
				exit(EXIT_SUCCESS);
			default :
				printf("wrong choice\n");
//				exit(EXIT_SUCCESS);
		}
	}
}



















