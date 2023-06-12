#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
	struct node *prev;
};
int print_dll(struct node *last){
	struct node *temp = NULL;
	temp = last-> next;
	do{
		printf("%d ",temp -> data);
		temp = temp -> next;
	} while( temp != last -> next);
	return 0;
}
struct node *create_dll(struct node *last, int size)
{
	struct node * new_node = NULL;
	struct node * temp = NULL;
	for(int i = 0; i < size; i++){
		new_node = (struct node *)malloc(sizeof(struct node));
		printf("enter data for cdll:\n");
		scanf("%d",&new_node -> data);
		new_node -> next = NULL;
		new_node -> prev = NULL;
		if(last == NULL){
			last = new_node;
			new_node -> next = new_node;
			new_node -> prev = new_node;
		} else {
			new_node -> prev = last;
			new_node -> next = last -> next;
			last -> next = new_node;
			last = new_node;
		}
	}
	return last;
}
struct node *insert_begin(struct node *last)
{
	struct node * new_node = NULL;
	struct node * temp = NULL;
	new_node = (struct node *)malloc(sizeof(struct node));
	printf("enter data for 1st position:\n");
	scanf("%d",&new_node -> data);
	new_node -> next = NULL;
	new_node -> prev = NULL;
	temp = last -> next; 
	if(last == NULL){
		last = new_node;
		new_node -> next = new_node;
		new_node -> prev = new_node;
	} else {
		new_node -> next = temp;
		new_node -> prev = last;
		temp -> prev = new_node;
		last -> next = new_node;
	}
	return last;
}
struct node *insert_last(struct node *last)
{
	struct node * new_node = NULL;
	struct node * temp = NULL;
	new_node = (struct node *)malloc(sizeof(struct node));
	printf("enter data for 1st position:\n");
	scanf("%d",&new_node -> data);
	new_node -> next = NULL;
	new_node -> prev = NULL;
	temp = last -> next;
	if(last == NULL){
		last = new_node;
		new_node -> next = new_node;
		new_node -> prev = new_node;
	} else {
		new_node -> next = last -> next;
		new_node -> prev = last;
		
		last = new_node;
	}
	return last;
}
int main(void)
{
	int size;
	struct node *last = NULL; 
	printf("enter size of csll: ");
	scanf("%d",&size);
	last = create_dll(last, size);
//	last = insert_begin(last);
//	printf("%d\n",get_length(last));	
	last = insert_last(last);
//	last = insert_any(last);
//	last = insert_before_pos(last);
//	last = insert_after_pos(last);
//	last = insert_before_number(last);
//	last = insert_after_number(last);
//	last = insert_mid(last);
	print_dll(last);
}
