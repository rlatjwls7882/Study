#include<stdio.h>
int main(){
	int a=1000000; //1,000,000 1�鸸 
	int b=2000000; //2,000,000 2�鸸
	
	long long c=a*b; //a*b =2,000,000,000,000?
	
	printf("c=%d\n", c);
	
	return 0; 
}
