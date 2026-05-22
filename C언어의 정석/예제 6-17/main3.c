#include <stdio.h>

int gv=100; //전역 변수의 정의와 선언. 초기화해야한다.

void printGv(void);

int main(void){
	printf("main() - gv=%d\n",gv);
	printGv();
	
	return 0;
} 
