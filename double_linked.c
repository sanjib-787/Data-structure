#include"../hdr/header.h"
int display_double ( struct double_node * temp )
{
	while ( temp != NULL ) {
			printf("%d\n", temp -> data);
			temp = temp ->next;
		}
	printf("done\n\n");
	return 0;
}
int double_insert_beginning ( struct double_node *head_double )
{
	int i;
	struct double_node *temp_double = NULL;
	struct double_node *new_node_double = NULL;
	if ( head_double == NULL ) {
		printf("Head ptr is null");
		exit ( EXIT_FAILURE );
	} else {
		new_node_double = (struct double_node*) malloc(sizeof(struct double_node));
		printf ("Enter the data to be entered at beginning: \n");
		scanf ("%d", &new_node_double -> data);
		new_node_double -> previous = NULL;
		new_node_double -> next = NULL;
		temp_double = head_double;
		head_double = new_node_double;
		new_node_double -> next = temp_double;
		temp_double -> previous = head_double;
 		temp_double = head_double;
		printf("After inserting data at beginning\n");
		display_double ( temp_double );
	}
	return 0;
}

int double_insert_end ( struct double_node *head )
{
	int i;
	struct double_node *temp = NULL;
	struct double_node *new_node = NULL;
	temp = head;
	new_node = (struct double_node *) malloc(sizeof(struct double_node));
	printf ("Enter the data to inserted at last: \n");
	scanf ("%d", &new_node -> data);
	new_node -> previous  = NULL;
	new_node -> next  = NULL;
	while ( temp -> next != NULL ) {
		temp = temp -> next;
	}
	temp -> next = new_node;
	new_node -> previous = temp;
 	temp = head;
	printf("After inserting data at end\n");
	display_double ( temp );
	return 0;
}

int double_insert_position ( struct double_node *head )
{
	int i = 1;
	struct double_node *temp = NULL;
	struct double_node *new_node = NULL;
	int pos;
	temp = head;
	new_node = (struct double_node*) malloc(sizeof(struct double_node));
	printf ("Enter the position at which data to entered\n");
	scanf ("%d", &pos);
	printf ("Enter the data to inserted at %d position: \n", pos);
	scanf ("%d", &new_node -> data);
	new_node -> previous  = NULL;
	new_node -> next  = NULL;
	while ( i < pos -1 ) {
		temp = temp -> next;
		i++;
	}
	new_node -> previous = temp;
	new_node -> next = temp -> next;
	temp -> next = new_node;
 	temp = head;
	printf("After inserting data at %d position:\n", pos);
	display_double ( temp );
	return 0;
}

int double_insert_before_position ( struct double_node *head )
{
	int i = 1;
	struct double_node *temp = NULL;
	struct double_node *new_node = NULL;
	int pos;
	temp = head;
	new_node = (struct double_node*) malloc(sizeof(struct double_node));
	printf ("Enter the position before which data to entered\n");
	scanf ("%d", &pos);
	printf ("Enter the data to inserted before %d position: \n", pos);
	scanf ("%d", &new_node -> data);
	new_node -> previous  = NULL;
	new_node -> next  = NULL;
	while ( i < pos - 1 ) {
		temp = temp -> next;
		i++;
	}
	new_node -> previous = temp;
	new_node -> next = temp -> next;
	temp -> next = new_node;
 	temp = head;
	printf("After inserting data at %d position:\n", pos-1);
	display_double ( temp );
	return 0;
}

int double_insert_after_position ( struct double_node *head )
{
	int i = 1;
	struct double_node *temp = NULL;
	struct double_node *new_node = NULL;
	int pos;
	temp = head;
	new_node = (struct double_node*) malloc(sizeof(struct double_node));
	printf ("Enter the position after which data to entered\n");
	scanf ("%d", &pos);
	printf ("Enter the data to inserted after %d position: \n", pos);
	scanf ("%d", &new_node -> data);
	new_node -> previous  = NULL;
	new_node -> next  = NULL;
	while ( i < pos ) {
		temp = temp -> next;
		i++;
	}
	new_node -> previous = temp;
	new_node -> next = temp -> next;
	temp -> next = new_node;
 	temp = head;
	printf("After inserting data at %d position:\n", pos+1);
	display_double ( temp );
	return 0;
}

int double_insert_in_middle ( struct double_node *head, int store )
{
	int i = 1;
	struct double_node *temp = NULL;
	struct double_node *new_node = NULL;
	temp = head;
	new_node = (struct double_node*) malloc(sizeof(struct double_node));
	printf ("Enter the data to inserted in the middle position: \n");
	scanf ("%d", &new_node -> data);
	new_node -> previous  = NULL;
	new_node -> next  = NULL;
	while ( i < store ) {
		temp = temp -> next;
		i++;
	}
	new_node -> previous = temp;
	new_node -> next = temp -> next;
	temp -> next = new_node;
 	temp = head;
	printf("After inserting data in the middle:\n");
	display_double ( temp );
	return 0;
}

int double_insert_in_penultimate ( struct double_node *head, int num )
{
	int i = 2;
	struct double_node *temp = NULL;
	struct double_node *new_node = NULL;
	temp = head;
	new_node = (struct double_node*) malloc(sizeof(struct double_node));
	printf ("Enter the data to inserted in the penultimate node: \n");
	scanf ("%d", &new_node -> data);
	new_node -> previous  = NULL;
	new_node -> next  = NULL;
	while ( i < num ) {
		temp = temp -> next;
		i++;
	}
	new_node -> previous = temp;
	new_node -> next = temp -> next;
	temp -> next = new_node;
 	temp = head;
	printf("After inserting penultimate node:\n");
	display_double ( temp );
	return 0;
}

int double_delete_at_beginning ( struct double_node *head )
{
	struct double_node *temp = NULL;
	temp = head;
	temp = temp -> next;
 	head = temp;
	temp -> previous = NULL;
	printf("After deleting beginning node:\n");
	display_double ( temp );
	return 0;
}

int double_delete_at_end ( struct double_node *head, int num )
{
	register int i = 1;
	struct double_node *temp = NULL;
	temp = head;
	while ( i < num ) {
		temp = temp -> next;
		i++;
	}
	temp = temp -> previous;
	temp -> next = NULL;
 	temp = head;
	printf("After deleting beginning node:\n");
	display_double ( temp );
	return 0;
}

int double_delete_at_position ( struct double_node *head, int num )
{
	register int i = 1;
	struct double_node *temp = NULL;
	struct double_node *previous_new = NULL;
	short int pos;
	temp = head;
	previous_new = head;
	printf ("Enter the position at which data to deleted\n");
	scanf ("%hd", &pos);
	if ( pos < 0 || pos > num) {
		printf("Enter invalid position\n");
		exit ( EXIT_FAILURE );
	} else {
		while ( i < pos ) {
			previous_new = temp;
			temp = temp -> next;
			i++;
	}
	previous_new -> next = temp -> next;
	temp -> previous = previous_new;
 	temp = head;
	printf("After deleting node at %hd position:\n", pos);
	display_double ( temp );
	}
	return 0;
}

int double_delete_before_position ( struct double_node *head, int num )
{
	register int i = 1;
	struct double_node *temp = NULL;
	struct double_node *temp_2 = NULL;
	short int pos;
	temp = head;
	temp_2 = head;
	printf ("Enter the position before which data to deleted\n");
	scanf ("%hd", &pos);
	if ( pos < 1 || pos > num) {
		printf("Entered invalid position\n");
		exit ( EXIT_FAILURE );
	} else {
		while ( i < pos - 1 ) {
			temp_2 = temp;
			temp = temp -> next;
			i++;
	}
	temp_2 -> next = temp -> next;
	temp -> previous = temp_2;
 	temp = head;
	printf("After deleting node before %hd position:\n", pos);
	display_double ( temp );
	}
	return 0;
}

int double_delete_after_position ( struct double_node *head, int num )
{
	register int i = 1;
	struct double_node *temp = NULL;
	struct double_node *temp_2 = NULL;
	short int pos;
	temp = head;
	temp_2 = head;
	printf ("Enter the position after which data to deleted\n");
	scanf ("%hd", &pos);
	if ( pos < 1 || pos >= num) {
		printf("Entered invalid position\n");
		exit ( EXIT_FAILURE );
	} else {
		while ( i < pos + 1 ) {
			temp_2 = temp;
			temp = temp -> next;
			i++;
	}
	temp_2 -> next = temp -> next;
	temp -> previous = temp_2;
 	temp = head;
	printf("After deleting node after %hd position:\n", pos);
	display_double ( temp );
	}
	return 0;
}

int double_delete_at_middle ( struct double_node *head, int store )
{
	register int i = 0;
	struct double_node *temp = NULL;
	struct double_node *temp_2 = NULL;
	temp = head;
	temp_2 = head;
	while ( i < store ) {
		temp_2 = temp;
		temp = temp -> next;
		i++;
	}
	temp_2 -> next = temp -> next;
	temp -> previous = temp_2;
 	temp = head;
	printf("After deleting node at middle :\n");
	display_double ( temp );
	return 0;
}

int double_delete_at_penultimate ( struct double_node *head, int num )
{
	register int i = 1;
	struct double_node *temp = NULL;
	struct double_node *temp_2 = NULL;
	temp = head;
	temp_2 = head;
	while ( i < num - 1 ) {
		temp_2 = temp;
		temp = temp -> next;
		i++;
	}
	temp_2 -> next = temp -> next;
	temp -> previous = temp_2;
 	temp = head;
	printf("After deleting node at penultimate :\n");
	display_double ( temp );
	return 0;
}
