#include<stdio.h>
int fact(int a){
	if(a<=1) return 1;
	return a*fact(a-1);
}

int main(void){
	int N;
	scanf("%d",&N);
	printf("%d",fact(N));
}