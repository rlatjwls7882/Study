#include<stdio.h>
#include<stdlib.h>
#include<string.h> //strlen(), memcpy()

//������ ���ڿ�(str)�� �Ϻθ� ��ȯ�ϴ� �Լ�
char* mySubstr(char *src, int fr,int to){ //fr<=x<to
	char* newStr;
	int len, diff=to-fr;
	
	if(src==NULL) return src;
	
	len=strlen(src);
	
	if(fr>to||to>len||fr<0) return NULL;
	
	//���ڿ��� �Ϻθ� ������ ������ �Ҵ����.(�ι���'\0'�� ����� ������ �ʿ�)
	newStr=(char*)malloc(sizeof(char)*(diff+1));
	
	memcpy(newStr,src+fr,diff); //src+fr���� diff���� ���ڸ� newStr�� ����
	*(newStr+diff)='\0'; //���� �ι��� ���� 
	
	return newStr;
} 

int main(void){
	char str[]="0123456789";
	printf("str=%s\n",str);
	printf("mySubstr(str, 3, 6)=%s\n",mySubstr(str,3,6));
	printf("mySubstr(str, 5, 10)=%s\n",mySubstr(str,5,10));
	printf("mySubstr(str, 6, 6)=%s\n",mySubstr(str,6,6));
	printf("mySubstr(str, 7, 5)=%s\n",mySubstr(str,7,5));
	printf("mySubstr(str, -1, 5)=%s\n",mySubstr(str,-1,5));
	return 0;
}
