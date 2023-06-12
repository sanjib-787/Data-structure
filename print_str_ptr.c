#include"../hdr/header.h"
#include<stdio_ext.h>
int main(void)
{
	int n;
	char *cptr[n];
	printf("enter how many strings:\n");
	scanf("%d",&n);
	__fpurge(stdin);
	for(int i=0;i<n;i++){
		*(cptr+i)=(char *)malloc(sizeof(char)*10);
		fgets(*(cptr+i),10,stdin);
		printf("%d\t%p\n",i+1,cptr[i]);
	}
	printf("strings are\n");
	for(int i=0;i<n;i++){
		printf("%s",*(cptr+i));
	/*	while(*(cptr[i])!='\0'){
			printf("%s\t",cptr[i]);
			cptr[i]++;
		}*/
	}
}

