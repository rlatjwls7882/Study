#include<stdio.h>
int main(){
	int sum=0, i=0;
	while((sum+=++i)<=100) // i�� 1�� �������Ѽ� sum�� ��� ���س�����.
	printf("%d - %d\n",i,sum);
	
	return 0; 
} 
