#include<stdio.h>
#include<stdlib.h>

int main(void){
	char* str="100101011";
	char* ptr;
	
	long L = strtol(str,&ptr,2);
	if(ptr!=str+strlen(str)) printf("��ȯ ����");
	else printf("%d",L);
	
	return 0;
}
