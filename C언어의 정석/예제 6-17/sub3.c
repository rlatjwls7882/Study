#include<stdio.h>

extern int gv; //���� ������ ������ ����. �ʱ�ȭ���� �ʴ´�.

void printGv(void){
	printf("printGv() - gv=%d\n",gv); //���� ������ ���� ��� 
} 
