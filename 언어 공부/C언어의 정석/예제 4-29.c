#include<stdio.h>
int main(){
	int i, tmp;
	for(i=1;i<=100;i++){
		printf("i=%d ",i);
		
		tmp=i;
		
		do{
			if(tmp%10%3==0&&tmp%10!=0) //tmp�� 3�� ������� Ȯ��(0�� ����)
			printf("¦"); 
		} while(tmp/=10); //tmp/=10�� tmp= tmp/10�� ����
		printf("\n"); 
	}
	return 0;
} 
