#include<stdio.h>

int x=100; //���� ����. �Լ� �ۿ� ����

int main(void){
	printf("x=%d\n",x); //x=100
	
	int x=200; //��������. �Լ� �ȿ� ����
	
	printf("x=%d\n",x); //x=100? 200? 200!!!
	
	return 0;
} 
