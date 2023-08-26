#include<stdio.h>
int main(){
	int N,tmp;
	scanf("%d",&N);
	for(int i=1;i<=N;i++) {
		tmp = (N-i)*2;
		
		for(int j=1;j<=i;j++) printf("*");
		
		while(tmp--) printf(" ");
		
		for(int j=1;j<=i;j++) printf("*");
		
		printf("\n");
	}
	for(int i=N-1;i>=1;i--) {
		tmp = (N-i)*2;
		
		for(int j=i;j>=1;j--) printf("*");
		
		while(tmp--) printf(" ");
		
		for(int j=i;j>=1;j--) printf("*");
		
		printf("\n");
	}
}