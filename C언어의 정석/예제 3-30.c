#include<stdio.h>
int main(){
	int i=0, j=0; // ','은 구분자
	int result=0;
	
	result = i=3, i++, j++; // (result = i=3), i++, j++;과 동일
	printf("i=%d, j=%d, result = %d\n",i,j,result); // ','은 구분자
	
	result = (i=3, i++, j++); // ','은 콤마 연산자 
	printf("i=%d, j=%d, result = %d\n",i,j,result); // ','은 구분자
	
	return 0; 
} 
