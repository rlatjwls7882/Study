#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int attack(int percent){
	return ((rand()%100)<percent) ? 1 : 0;
}

int main(void){
	int i;
	
	srand((unsigned)time(NULL));
	
	for(i=0;i<10;i++)
		printf("%d",attack(25));
	puts("");
	
	return 0;
}
