#include<stdio.h>

char* getUserInput(char* input){
	printf("�ܾ �ϳ� �Է��ϼ���.>");
	scanf("%s",input);
	
	return input;
}

int main(void){
	char input[20];
	char* str=getUserInput(input); //�Ű������� ���� �迭�� ����
	
	printf("�Է¹��� �ܾ�:%s\n",str);
	return 0; 
}
