#include<stdio.h>

int main(){
	int num;
	int i,j;
	
	printf("*을 출력할 라인의 수를 입력하세요.>");
	scanf("%d",&num);
	for(i=1;i<num;i++){
		for(j=1;j<=i;j++) printf("*");
	printf("\n");
	}
	
	return 0;
}
