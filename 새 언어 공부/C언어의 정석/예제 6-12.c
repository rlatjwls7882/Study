#include<stdio.h>
long long factorial(int n){
	if(n<=0||n>20) return -1; //�Ű������� ��ȿ�� �˻� 
	
	if(n<=1) return 1;
	return n*factorial(n-1);
}

int main(){
	int i=0;
	int n=21;
	long long result = 0;
	
	for(i=1;i<=n;i++){
		result = factorial(i);
		
		if(result==-1){
			printf("��ȿ���� ���� ���Դϴ�.(0<n<=20):%d\n",n);
			break;
		}
		printf("%2d!=%20lld\n",i,result);
	}
	
	return 0;
} 
