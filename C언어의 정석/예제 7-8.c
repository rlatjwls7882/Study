#include<stdio.h>

int main(){
	int i=100;
	int* pi= &i; //���� i�� ����Ű�� ������
	int** ppi= &pi; //������ pi�� ����Ű�� ������(�������� ������)
	int* pi2=(int*)&pi; //pi�� ���� pi2�� �����Ѵ�.
	
	printf("i=%d\n",i);
	printf("&i=%p\n",&i);
	printf("pi=%p\n",pi);
	printf("&pi=%p\n",&pi); 
	printf("ppi=%p\n",ppi); 
	printf("*ppi=%p\n",*ppi);
	printf("**ppi=%d\n",**ppi);
	printf("pi2=%p\n",pi2);
	printf("*pi2=%p\n",*pi2);
	printf("**(int**)pi2=%d\n",**(int**)pi2);
	printf("sizeof(pi)=%d\n",sizeof(pi));
	printf("sizeof(ppi)=%d\n",sizeof(ppi));
	
	return 0;
} 
