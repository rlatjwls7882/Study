#include<stdio.h>
#include<string.h>
int main(){
	char str[]="Hello";
	int LEN = sizeof(str)/sizeof(str[0]);
	int i;
	
	printf("%s\n",str); //Hello
	
	strcpy(str,"12345"); //char �迭 str�� "12345"�� ���� 
	printf("%s\n",str); //12345 
	
	str[2]='\0'; //�� ��° ���ڸ� �� ���ڷ� ���� 
	printf("%s\n",str); //12
	
	for(i=0;i<LEN;i++) printf("str[%d]=%c, %d\n",i,str[i],str[i]);
	
	return 0;
}
