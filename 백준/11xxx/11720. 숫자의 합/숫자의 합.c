#include<stdio.h>

int main(){
	int N,sum=0;
	scanf("%d",&N);
	
	char num[N+1];
	scanf("%s",num);
	
	for(int i=0;i<N;i++)
		sum+=num[i]-'0';
		
	printf("%d",sum);
	
	return 0;
}