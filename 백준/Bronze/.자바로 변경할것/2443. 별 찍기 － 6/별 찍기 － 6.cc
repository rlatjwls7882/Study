#include<stdio.h>
int main(){
	int N,tmp;
	scanf("%d",&N);
	for(int i=N;i>=1;i--) {
		tmp = 2*i-1;
		for(int j=N-i;j>=1;j--) printf(" ");
		while(tmp--) printf("*");
		printf("\n");
	}
}