#include<stdio.h>

int main(){
	int input;
	printf("���ڸ� �ϳ� �Է��ϼ���.>");
	scanf("%d", &input);
	
	if(input==0) printf("�Է��Ͻ� ���ڴ� 0�Դϴ�.\n");
	
	if(input!=0){
		printf("�Է��Ͻ� ���ڴ� 0�� �ƴմϴ�.\n");
		printf("�Է��Ͻ� ���ڴ� %d�Դϴ�.\n",input);
	}
	
	return 0;
} 
