#include"../hdr/header.h"
#include<string.h>
#define SIZE 20
int main(void)
{
	int n;
	printf("enter how many strings:\n");
	scanf("%d", &n);
	char *str1[n];
	printf("enter the strings:\n");
	for( int i=0; i < n; i++){
		str1[i]=(char *)malloc(sizeof(char) * SIZE);
		scanf("%s",str1[i]);
	}
	printf("before sort\n");
	for( int i=0; i < n; i++){
		printf("%s\n",str1[i]);
	}
	string_sort(n,str1);
	printf("after sort\n");
	for( int i=0; i < n; i++){
		printf("%s\n",str1[i]);
	}
}
char *string_sort(int n,char *str1[n])
{
	char *cptr1;
	int temp;
	for(int i = 0; i < n-1; i++ ){
		for( int j = 0 ; j < n-1-i; j++){
			temp = strcmp(str1[j],str1[j+1]);
			if(temp > 0){
//				string_swap(str1[j],str1[j+1]);
				cptr1=str1[j];
				str1[j]=str1[j+1];
				str1[j+1]=cptr1;
			}
		}
	}	
	return *str1;
}
