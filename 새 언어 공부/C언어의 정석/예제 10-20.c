#include<stdio.h>
#include<string.h>

int main(void){
	char* str="abc999xyz3456oo2z";
	char* numStr="0123456789";
	int cnt=0;
	
	printf("str=%s\n",str);
	
	while(str&&*str){ //while(str!=NULL&&*str!='\0')
		str=strpbrk(str,numStr); //str�� ���Ե� ù��° ������ �ּҸ� ��ȯ
		
		if(str){ //if(str!=NULL) //str�� NULL�� �ƴϸ�, 
			cnt++;
			str+=strspn(str,numStr); //������ ���̸�ŭ str�� ������Ų�� 
		} 
	}
	
	printf("cnt=%d\n",cnt);
	return 0;
}
