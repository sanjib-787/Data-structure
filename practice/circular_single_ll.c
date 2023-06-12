#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
int get_length(struct node *last)
{
	int len = 0;
	struct node *temp;
	temp = last-> next;
	do{
		//printf("%d ",temp -> data);
		len++;
		temp = temp -> next;
	} while( temp != last -> next);
	return len;
}
int print_ll(struct node *tail)
{
	struct node *temp;
	temp = tail-> next;
	do{
		printf("%d ",temp -> data);
		temp = temp -> next;
	} while( temp != tail -> next);
}
struct node *create_ll(struct node *last, int size)
{
	struct node *new_node = NULL;
	struct node *temp = NULL;
	for(int i = 0; i < size; i++) {
		new_node = (struct node *)malloc(sizeof(struct node));
		printf("enter data: ");
		scanf("%d",&new_node -> data);
		new_node -> next = NULL;
		if(last == NULL){
			last = new_node;
			last -> next = new_node;
		} else {
			new_node -> next = last -> next;
			last -> next = new_node;
			last = new_node;
		}
	}
	return last;
}
struct node *insert_begin( struct node *last)
{
	struct node *new_node = NULL;
	new_node = (struct node *)malloc(sizeof(struct node));
	printf("enter data for 1st position: ");
	scanf("%d",&new_node -> data);
	if( last == NULL ){
		last = new_node;
		last -> next = new_node;
	} else {
		new_node -> next = last -> next;
		last -> next = new_node;
	}
	return last;
}
struct node *insert_last(struct node * last)
{
	struct node *new_node = NULL;
	new_node = (struct node *)malloc(sizeof(struct node));
	printf("enter data for last position: ");
	scanf("%d",&new_node -> data);
	new_node -> next = NULL;
	if( last == NULL ){
		last = new_node;
		last -> next = new_node;
	} else {
		new_node -> next = last -> next;
		last -> next = new_node;
		last = new_node;
	}
	return last;
}
struct node *insert_any(struct node *last){
	struct node *new_node = NULL;
	struct node *temp = NULL;
	int pos, i = 1, len;
	len = get_length(last);
	printf("enter position: ");
	scanf("%d",&pos);
	if(pos < 0 || pos > len){
		printf("invalid operation\n");
	} else if( pos == 1){
		last = insert_begin(last);
	} else {
		new_node = (struct node *)malloc(sizeof(struct node));
		printf("enter data for at any position: ");
		scanf("%d",&new_node -> data);
		temp = last -> next;
		while(i < pos-1) {
			temp = temp -> next;
			i++;
		}
		new_node -> next = temp -> next;
		temp -> next = new_node;
	}	
	return last;
}
struct node *insert_before_pos(struct node *last){
	struct node *new_node = NULL;
	struct node *temp = NULL;
	int pos, i = 1, len;
	len = get_length(last);
	printf("enter position: ");
	scanf("%d",&pos);
	//temp = last -> next;
	if(pos < 0 || pos > len){
		printf("invalid operation\n");
	} else if( pos == 1){
		last = insert_begin(last);
	} else {
		new_node = (struct node *)malloc(sizeof(struct node));
		printf("enter data for at any position: ");
		scanf("%d",&new_node -> data);
		temp = last -> next;
		while(i < pos-2) {
			temp = temp -> next;
			i++;
		}
		new_node -> next = temp -> next;
		temp -> next = new_node;
	}	
	return last;
}
struct node *insert_after_pos(struct node *last){
	struct node *new_node = NULL;
	struct node *temp = NULL;
	int pos, i = 1, len;
	len = get_length(last);
	printf("enter position: ");
	scanf("%d",&pos);
	if(pos < 0 || pos > len){
		printf("invalid operation\n");
	} else if( pos == 1){
		last = insert_begin(last);
	} else {
		new_node = (struct node *)malloc(sizeof(struct node));
		printf("enter data for at any position: ");
		scanf("%d",&new_node -> data);
		temp = last -> next;
		while(i < pos) {
			temp = temp -> next;
			i++;
		}
		new_node -> next = temp -> next;
		temp -> next = new_node;
	}	
	return last;
}
struct node *insert_before_number(struct node *last)
{
	struct node *new_node = NULL;
	struct node *temp = NULL;
	struct node *temp1 = NULL;
	int num;
	printf("enter number where you want to insert: ");
	scanf("%d",&num);
	temp = last -> next;
	while(temp->next != last ->next){
		temp1 = temp;
		temp = temp -> next;
		if(num == temp->data){
			new_node = (struct node *)malloc(sizeof(struct node));
			printf("enter data for at any position: ");
			scanf("%d",&new_node -> data);
			new_node -> next = temp1 -> next;
			temp1 -> next = new_node;
		}
		if(temp->next == last->next && num != temp->data){
			printf("number not found\n");
			exit(EXIT_FAILURE);
		}
	}
	return last;
}
struct node *insert_after_number(struct node *last)
{
	struct node *new_node = NULL;
	struct node *temp = NULL;
	int num;
	printf("enter number where you want to insert: ");
	scanf("%d",&num);
	temp = last -> next;
	while(temp->next != last ->next){
		if(num == temp->data){
			new_node = (struct node *)malloc(sizeof(struct node));
			printf("enter data for at any position: ");
			scanf("%d",&new_node -> data);
			new_node -> next = temp -> next;
			temp -> next = new_node;
		}
		if(temp->next == last->next && num != temp->data){
			printf("number not found\n");
			exit(EXIT_FAILURE);
		}
		temp = temp -> next;
	}
	return last;
}
struct node *insert_mid(struct node *last){
	struct node *new_node = NULL;
	struct node *temp = NULL;
	int pos, i = 1, len;
	len = get_length(last);
	pos = len / 2;
	if(pos < 0 || pos > len){
		printf("invalid operation\n");
	} else if( pos == 1){
		last = insert_begin(last);
	} else {
		new_node = (struct node *)malloc(sizeof(struct node));
		printf("enter data for at any position: ");
		scanf("%d",&new_node -> data);
		temp = last -> next;
		while(i < pos) {
			temp = temp -> next;
			i++;
		}
		new_node -> next = temp -> next;
		temp -> next = new_node;
	}	
	return last;
}
int main(void)
{
	int size;
	struct node *last = NULL; 
	printf("enter size of csll: ");
	scanf("%d",&size);
	last = create_ll(last, size);
	//last = insert_begin(last);
	printf("%d\n",get_length(last));	
	//last = insert_last(last);
//	last = insert_any(last);
//	last = insert_before_pos(last);
//	last = insert_after_pos(last);
//	last = insert_before_number(last);
//	last = insert_after_number(last);
	last = insert_mid(last);
	print_ll(last);
}
