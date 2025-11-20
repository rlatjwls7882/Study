#include<stdio.h>
int factorial(int n){
	if(n==1) return 1; //n의 값이 1이면, 1을 반환한다.
	return n*factorial(n-1); //재귀호출 
}
int main(){
	int result = factorial(5);
	
	printf("%d!=%d\n",5,result);
	
	return 0;
} 
