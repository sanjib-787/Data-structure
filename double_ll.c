#include"../hdr/header.h"
struct Node {
	int data;
	struct Node *next;
	struct Node *prev;
};
struct Node *create_dll( struct Node *head, int size)
{
	struct Node *temp = NULL;
	struct Node *new_node = NULL;
	for( int i = 0; i < size; i++){
		new_node = ( struct Node * ) malloc ( sizeof(struct Node *));
		printf("enter data for dll:\n");
		scanf("%d",&new_node -> data );
		new_node -> next = NULL;
		if( head == NULL ){
			head = new_node;
			temp = new_node;
		} else {
			temp -> next = new_node;
			new_node -> prev = temp;
			temp = temp -> next;
		}
	}
	return head;
}
int print_dll( struct Node *temp )
{
	while( temp != NULL ){
		printf("%d ",temp -> data);
		temp = temp -> next;
	}	
}
struct Node *insert_beginning ( struct Node *head )
{
	int i;
	struct Node *temp = NULL;
	struct Node *new_node = NULL;
	if ( head == NULL ) {
		printf("Head ptr is null");
		exit ( EXIT_FAILURE );
		} else {
	new_node = (struct Node*) malloc(sizeof(struct Node));
	printf ("Enter the data to be entered at beginning: \n");
	scanf ("%d", &new_node -> data);
	temp = head;
	head = new_node;
	new_node -> next = temp;
	temp = head;
	}
	return head;
	} 
struct Node *insert_end ( struct Node *head )
{
	int i;
	struct Node *temp = NULL;
	struct Node *new_node = NULL;
	temp = head;
	new_node = (struct Node*) malloc(sizeof(struct Node));
	printf ("Enter the data to inserted at last: \n");
	scanf ("%d", &new_node -> data);
	new_node -> next  = NULL;
	while ( temp -> next != NULL ) {
		temp = temp -> next;
	}
	temp -> next = new_node;
	temp = head;
	return head;
} 
struct Node *insert_position ( struct Node *head )
{
	int i = 2;
	struct Node *temp = NULL;
	struct Node *new_node = NULL;
	int pos;
	temp = head;
	new_node = (struct Node*) malloc(sizeof(struct Node));
	printf ("Enter the position at which data to entered\n");
	scanf ("%d", &pos);
	printf ("Enter the data to inserted at %d position: \n", pos);
	scanf ("%d", &new_node -> data);
	new_node -> next  = NULL;
	while ( i < pos ) {
		temp = temp -> next;
		i++;
		}
	new_node -> next = temp -> next;
	temp -> next = new_node;
	temp = head;
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
	head = create_dll( head, size);
	while(1){
		printf("1. Insert at the beginning\n2. Insert at the end\n3. Insert at a given position\n4. Insert before a given position\n5. Insert after a given position\n6. Insert before a given number\n7. Insert after a given number\n8. Insert at the middle\n9. Insert at penultimate node\n10. print\n");
		printf("enter ur choice:\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				head = insert_beginning( head );
				break;
			case 2:
				head = insert_end( head );
				break;
			case 3:
				head = insert_position( head );
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				break;
			case 10:
				print_dll( head );
				exit(EXIT_SUCCESS);
			default :
				printf("wrong choice\n");
//				exit(EXIT_SUCCESS);
		}
	}
}
