#include<stdio.h>
int string_swap( char *cptr1, char *cptr2)
{
	char *temp = cptr1;
	cptr1 = cptr2;
	cptr2 = temp;
}
