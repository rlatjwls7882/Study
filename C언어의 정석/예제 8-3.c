#include<stdio.h>

void changeX(char* x){ //�Ű������� Ÿ���� ������ 
	x= "ZZZ";
} 

int main(void){
	char* x="AAA";
	printf("%s\n",x);
	changeX(x); //������ x�� ��(�ּ�)�� �Ѱ��ش� 
	printf("%s\n",x);
	
	return 0;
}
