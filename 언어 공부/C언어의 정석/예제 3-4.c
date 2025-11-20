#include<stdio.h>
int main(){
	int i=5;
	int j=0;
	
	j = i++; //후위형
	printf("j=i++; 실행후, i=%d, j=%d\n",i,j);
	 
	i=5;
	j=0;
	
	j=++i; //전위형
	printf("j=++i; 실행후, i=%d, j=%d\n",i,j);
	
	return 0; 
	
} 
