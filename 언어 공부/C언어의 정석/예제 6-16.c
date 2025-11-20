#include<stdio.h>

int x=100; //전연 변수. 함수 밖에 선언

int main(void){
	printf("x=%d\n",x); //x=100
	
	int x=200; //지연변수. 함수 안에 선언
	
	printf("x=%d\n",x); //x=100? 200? 200!!!
	
	return 0;
} 
