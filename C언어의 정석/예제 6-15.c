#include<stdio.h>

int x; // ���� ����. �Լ� �ۿ� ����

void func1(void){
	int y; //��������. �Լ��ȿ� ����
	x=1; //OK
	y=2; //OK
//	z=3; //����
//	x2=4; //����. �����Ϸ��� ���� x2�� ���� ������ ���� ����. 

	printf("func1() x=%d\n",x);
	printf("func1() y=%d\n",y);
//	printf("func1() z=%d\n",z); //����. 
} 

int x2; //��������. �Լ� �ۿ� ����

void func2(void){
	int z; //��������. �Լ��ȿ� ����
	x=10; //OK
//	y=20; //���� 
	z=30; //OK
	x2=40; //OK. ���� x2�� ���� ������ �˰� ����. 
	
	printf("func2() x=%d\n",x);
//	printf("func2() y=%d\n",y); //����. ��ȿ���� ���� ���� 
	printf("func2() z=%d\n",z);
	printf("func2() x2=%d\n",x2);
} 
int main(void){
	func1();
	func2();
	return 0;
} 
