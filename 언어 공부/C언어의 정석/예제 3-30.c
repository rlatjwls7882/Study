#include<stdio.h>
int main(){
	int i=0, j=0; // ','�� ������
	int result=0;
	
	result = i=3, i++, j++; // (result = i=3), i++, j++;�� ����
	printf("i=%d, j=%d, result = %d\n",i,j,result); // ','�� ������
	
	result = (i=3, i++, j++); // ','�� �޸� ������ 
	printf("i=%d, j=%d, result = %d\n",i,j,result); // ','�� ������
	
	return 0; 
} 
