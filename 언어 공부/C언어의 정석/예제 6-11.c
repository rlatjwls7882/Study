#include<stdio.h>
int factorial(int n){
	if(n==1) return 1; //n�� ���� 1�̸�, 1�� ��ȯ�Ѵ�.
	return n*factorial(n-1); //���ȣ�� 
}
int main(){
	int result = factorial(5);
	
	printf("%d!=%d\n",5,result);
	
	return 0;
} 
