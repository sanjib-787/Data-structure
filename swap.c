#include<stdio.h>
int swap(int *var1, int *var2)
{
	int temp = *var1;
	*var1 = *var2;
	*var2 = temp;
}
