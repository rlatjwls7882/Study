#include<stdio.h>
#include<stdlib.h> //atoi()�� ����ϱ� ���� �߰�

int main(int argc,char* argv[]){
	int i, num;
	
	printf("argc=%d\n",argc);
	
	for(i=0;i<argc;i++)
		printf("argv[%d]=%s\n",i,argv[i]);
		
	num=atoi(argv[2]); //���ڿ� "123"�� ���� 123���� ��ȯ
	printf("num=%d\n",num*100);
	
	return 1; //�����ڵ�(exit code)�� 1�� ���� 
} 
