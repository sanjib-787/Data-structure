#include<stdio.h>
int str_swap( char *cptr1[])
{
	char *temp = cptr1[0];
	cptr1[0] = cptr1[1];
	cptr1[1] = temp;
}
