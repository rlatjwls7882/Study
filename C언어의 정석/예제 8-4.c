#include<stdio.h>

void changeX(char** px){
	*px= "ZZZ"; //���ڿ� ��� "ZZZ"�� �ּҸ� ������ *px(main�Լ��� x)�� ���� 
} 

int main(void){
	char* x="AAA";
	
	printf("%s\n",x);
	changeX(&x); //������ x�� �ּҸ� �Ѱ��ش� 
	printf("%s\n",x);
	
	return 0;
}
