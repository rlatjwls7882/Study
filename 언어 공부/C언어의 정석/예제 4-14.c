#include<stdio.h>
int main(){
	int sum = 0; //합계를 저장하기 위한 변수 
	int i;
	
	for(i=1;i<=10;i++){
		sum +=i;
		printf("1부터 %2d까지의 합: %2d\n",i,sum);
	}
	
	return 0;
} 
