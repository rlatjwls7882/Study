#include<stdio.h>

int add(int a,int b){
	return a+b;
} 

int main(void){
	int (*pf)(void)=(int(*)(void))add; //����ȯ ���� ����
	int result=pf(); //�Լ� ������ pf�� Ÿ�԰� ȣ�������� ��ġ
	
	printf("result=%d\n",result);
	
	return 0; 
}
