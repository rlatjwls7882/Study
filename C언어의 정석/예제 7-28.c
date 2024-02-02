#include<stdio.h>

int main(void){
	char chArr[10];
	char *pch="ABC";
	int i=0;
	
	for(i;*pch;i++)
		chArr[i]=pch[i];
	
	printf("chArr=%s\n",chArr);
	return 0;
} 
