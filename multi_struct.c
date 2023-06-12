#include<stdio.h>
#include<stdlib.h>
struct d {
	int * p;
	char ch;
	short int sh;
};
struct c {
	char * name;
	struct d *dt;
};
struct b {
	int num;
	struct c ct;
};
struct a {
	int  *a;
	struct b *bt;
};
int main(void)
{
	struct a *ptr = NULL;
	ptr = (struct a *)malloc(sizeof(struct a));
	ptr -> a = (int *)malloc(sizeof(int));	//memory for a
	ptr -> bt = (struct b *)malloc(sizeof(struct b)); // memory for bt
	ptr -> bt -> ct.name= (char *)malloc(sizeof(char));	//memory for name
	ptr -> bt -> ct.dt = (struct d *)malloc(sizeof(struct d));	
	ptr -> bt -> ct.dt -> p= (int *)malloc(sizeof(int));	
	printf("a val is:\n");
	scanf("%d",ptr -> a);
	printf("num val is:\n");
	scanf("%d",&ptr -> bt -> num);
	printf("name val is:\n");
	scanf("%s",ptr -> bt -> ct.name);
	printf("p val is:\n");
	scanf("%d",ptr -> bt -> ct.dt -> p);
	printf("ch val is:\n");
	scanf("%c",&ptr -> bt -> ct.dt -> ch);
	getchar();
	printf("sh val is:\n");
	scanf("%hd",&ptr -> bt -> ct.dt -> sh);
	free( ptr -> bt -> ct.dt -> p );
	free( ptr -> bt -> ct.dt );
	free( ptr -> bt -> ct.name);
	free( ptr -> bt );
	free( ptr -> a);
	free( ptr );
	return 0;
}
