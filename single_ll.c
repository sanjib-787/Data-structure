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
	printf("\n");	
}
struct Node *create_ll(struct Node *head, struct Node *temp, int size)
{
	struct Node *new_node = NULL;
	for( int i = 0; i < size; i++){
		new_node = ( struct Node * ) malloc ( sizeof(struct Node));
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
struct Node *insert_begning( struct Node *head )
{
	struct Node *new_node = NULL;
	struct Node *temp = NULL;
	new_node = ( struct Node *) malloc ( sizeof( struct Node * ) );
	printf("enter value for storing at begning :");
	scanf( "%d", &new_node -> data );
	temp = head;
	head = new_node;
	head -> next = temp;
    return head;
}
struct Node *insert_end( struct Node *head )
{
	struct Node *new_node = NULL;
	struct Node *temp = NULL;
	new_node = ( struct Node *) malloc ( sizeof( struct Node * ) );
	printf("enter value for storing at end :");
	scanf( "%d", &new_node -> data );
	new_node -> next = NULL;
	temp = head;
	while ( temp -> next != NULL ){
		temp = temp -> next;
	}
	temp -> next = new_node;
	return head;
}
struct Node *insert_position(struct Node *head, int* newsize)
{
	int i=1,pos, count = 0;
	struct Node *new_node = NULL;
	struct Node *temp = NULL;
	struct Node *temp1 = NULL;
	printf("enter position:\n");
	scanf("%d",&pos);
	new_node = ( struct Node *) malloc ( sizeof( struct Node * ) );
	printf("enter value for storing at end :");
	scanf( "%d", &new_node -> data );

	if (pos > *newsize + 1 || pos <= 0) {
		printf( "position is greater than no of nodes.\n");
		return head;
	} else if(pos == 1) {
		temp = head;
		head = new_node;
		head -> next = temp;

	} else {
		temp = head;
		temp1 = head;
		while( i < pos ){
			temp1 = temp;
			temp = temp -> next;
			i++;
			}
		temp1 -> next = new_node;
		new_node -> next = temp;
		*newsize++;
		}
	return head;
}
struct Node *insert_before_position(struct Node *head, int *newsize)
{
	int i=1,pos, count = 0;
	struct Node *new_node = NULL;
	struct Node *temp = NULL;
	struct Node *temp1 = NULL;
	printf("enter position:\n");
	scanf("%d",&pos);
	new_node = ( struct Node *) malloc ( sizeof( struct Node * ) );
	printf("enter value for storing at end :");
	scanf( "%d", &new_node -> data );

	if (pos > *newsize + 1 || pos <= 0) {
		printf( "position is greater than no of nodes.\n");
		return head;
	} else if(pos == 1) {
		temp = head;
		head = new_node;
		head -> next = temp;

	} else {
	temp = head;
	temp1 = head;
	while( i < pos-1 ){
		temp1 = temp;
		temp = temp -> next;
		i++;
	}
	temp1 -> next = new_node;
	new_node -> next = temp;
	*newsize++;
	}
	return head;

}
struct Node *insert_after_position(struct Node *head, int *newsize)
{
	int i=1,pos, count = 0;
	struct Node *new_node = NULL;
	struct Node *temp = NULL;
	struct Node *temp1 = NULL;
	printf("enter position:\n");
	scanf("%d",&pos);
	new_node = ( struct Node *) malloc ( sizeof( struct Node * ) );
	printf("enter value for storing at end :");
	scanf( "%d", &new_node -> data );

	if (pos > *newsize + 1 || pos <= 0) {
		printf( "position is greater than no of nodes.\n");
		return head;
	} else if(pos == 1) {
		temp = head;
		head = new_node;
		head -> next = temp;

	} else {
	temp = head;
	temp1 = head;
	while( i < pos + 1 ){
		temp1 = temp;
		temp = temp -> next;
		i++;
	}
	temp1 -> next = new_node;
	new_node -> next = temp;
	*newsize++;
	}
	return head;
}
struct Node *insert_before_number( struct Node *head ,int *newsize)
{
	int i=1, num, count = 0;
	struct Node *new_node = NULL;
	struct Node *temp = NULL;
	struct Node *temp1 = NULL;
	printf("enter number:\n");
	scanf("%d",&num);
	new_node = ( struct Node *) malloc ( sizeof( struct Node * ) );
	printf("enter value for storing before number :");
	scanf( "%d", &new_node -> data );
	temp = head;
	temp1 = head;
	while ( temp -> next != NULL ){
		temp1 = temp;
		temp = temp -> next;
//		i++;
		if( num == temp -> data){
//			printf("i is %d\n",i);
			temp1 -> next = new_node;
			new_node -> next = temp;
		} else {
			printf("number is not present");
		}
	}

	return head;
}
struct Node *insert_after_number( struct Node *head ,int *newsize)
{
	int i=1,pos, num, count = 0;
	struct Node *new_node = NULL;
	struct Node *temp = NULL;
	struct Node *temp1 = NULL;
	printf("enter number:\n");
	scanf("%d",&num);
	new_node = ( struct Node *) malloc ( sizeof( struct Node * ) );
	printf("enter value for storing before number :");
	scanf( "%d", &new_node -> data );
	temp = head;
	temp1 = head;
	while ( temp -> next != NULL ){
		temp1 = temp;
		temp = temp -> next;
		if( num == temp -> data){
			break;
//			new_node -> next = temp1;
//			temp -> next = new_node;
		}
		i++;
	}
	temp = head;
	temp1 = head;
	while( i < pos + 1 ){
		temp1 = temp;
		temp = temp -> next;
		i++;
	}
	temp1 -> next = new_node;
	new_node -> next = temp;
	*newsize++;
	return head;
}
struct Node *insert_mid_position(struct Node *head, int* newsize)
{
	int i=1,pos, count = 0;
	struct Node *new_node = NULL;
	struct Node *temp = NULL;
	struct Node *temp1 = NULL;
//	printf("enter position:\n");
//	scanf("%d",&pos);
	pos = (*newsize) / 2;
	new_node = ( struct Node *) malloc ( sizeof( struct Node * ) );
	printf("enter value for storing at end :");
	scanf( "%d", &new_node -> data );

	if (pos > *newsize + 1 || pos <= 0) {
		printf( "position is greater than no of nodes.\n");
		return head;
	} else if(pos == 1) {
		temp = head;
		head = new_node;
		head -> next = temp;

	} else {
	temp = head;
	temp1 = head;
	while( i < pos + 1 ){
		temp1 = temp;
		temp = temp -> next;
		i++;
	}
	temp1 -> next = new_node;
	new_node -> next = temp;
	*newsize++;
	}
	return head;
}
struct Node *insert_penultimate_position(struct Node *head, int* newsize)
{
	int i=1,pos, count = 0;
	struct Node *new_node = NULL;
	struct Node *temp = NULL;
	struct Node *temp1 = NULL;
	//printf("enter position:\n");
	//scanf("%d",&pos);
	pos = (*newsize) - 1;
	new_node = ( struct Node *) malloc ( sizeof( struct Node * ) );
	printf("enter value for storing at end :");
	scanf( "%d", &new_node -> data );

	if (pos > *newsize + 1 || pos <= 0) {
		printf( "position is greater than no of nodes.\n");
		return head;
	} else if(pos == 1) {
		temp = head;
		head = new_node;
		head -> next = temp;

	} else {
	temp = head;
	temp1 = head;
	while( i < pos + 1 ){
		temp1 = temp;
		temp = temp -> next;
		i++;
	}
	temp1 -> next = new_node;
	new_node -> next = temp;
	*newsize++;
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
		printf("1. Insert at the beginning\n2. Insert at the end\n3. Insert at a given position\n4. Insert before a given position\n5. Insert after a given position\n6. Insert before a given number\n7. Insert after a given number\n8. Insert at the middle\n9. Insert at penultimate node\n10. print\n");
		printf("enter ur choice:\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				head = insert_begning( head );
				break;
			case 2:
				head = insert_end( head );
				break;
			case 3:
				head = insert_position( head , &size);
				break;
			case 4:
				head = insert_before_position( head, &size);
				break;
			case 5:
				head = insert_after_position( head, &size);
				break;
			case 6:
				head = insert_before_number( head, &size);
				break;
			case 7:
				head = insert_after_number( head, &size);
				break;
			case 8:
				head = insert_mid_position( head, &size);
				break;
			case 9:
				head = insert_penultimate_position( head, &size);
				break;
			case 10:
				print_ll( head );
				break;
				//exit(EXIT_SUCCESS);
			default :
				printf("wrong choice\n");
				exit(EXIT_SUCCESS);
		}
	}
}
