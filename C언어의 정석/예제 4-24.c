#include<stdio.h>
int main(){
	int i,j;
	
	i=11;
	
	printf("��, ���� ī��Ʈ�ٿ��� �����մϴ�.\n");
	
	while(i--){
		printf("%d\n",i);
		
		for(j=0;j<1000000000;j++) ;
	}
	printf("GAME OVER\n");
	
	return 0;
} 
