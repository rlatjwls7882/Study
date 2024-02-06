#include<stdio.h> 
#include<stdlib.h>

int main(int argc,char* argv[]){
	int num1, num2, result=0;
	char op;
	
	if(argc!=4){ //4��(�������� ����)�� ���� �Է����� ������ 
		printf("USAGE: \"Desktop\\C����� ����\\���� 8-15\" NUM1 OP NUM2\n"); //�������� �����ְ�
		exit(1); //���α׷� ����. �����ڵ�(exit cod)�� 1�� ����
//		return 1; 
	}
	
	num1=atoi(argv[1]);
	op=argv[2][0];
	num2=atoi(argv[3]);
	
	switch(op){
		case '+':
			result=num1+num2;
			break;
		case '-':
			result=num1-num2;
			break;
		case '*':
			result=num1*num2;
			break;
		case '/':
			result=num1/num2;
			break;
		default:
			printf("�������� �ʴ� �����Դϴ�.\n");
	}
	
	printf("result=%d\n",result);
	return 0;
}
