#include<stdio.h>
#include<string.h> //strlen()�� ����ϱ� ���� �߰�
int main(){
	char str[]="Hello";
	char chArr[]={'H','e','l','l','o'};
	int i;
	int LEN = sizeof(str)/ sizeof(str[0]); //�迭 str�� ����
	 
	printf("str=%s\n", str); //���ڿ��� ������ %s�� �����Ѵ�
	printf("chArr=%s\n",chArr);
	for(i=0;str[i]!='\0';i++); //str�� ù���� ��Һ���, �ι��ڸ� ���������� i�� ���� ����
	
	printf("LEN=%d\n",LEN);
	printf("i=%d\n",i);
	printf("strlen(str)=%d\n",strlen(str));
	
	return 0; 
} 
