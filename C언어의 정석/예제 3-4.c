#include<stdio.h>
int main(){
	int i=5;
	int j=0;
	
	j = i++; //������
	printf("j=i++; ������, i=%d, j=%d\n",i,j);
	 
	i=5;
	j=0;
	
	j=++i; //������
	printf("j=++i; ������, i=%d, j=%d\n",i,j);
	
	return 0; 
	
} 
