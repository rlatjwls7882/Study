#include<stdio.h>

static int sv; //���� ���� - �Լ� �ۿ� ����. ��ȿ������ �ҽ����� ��ü

void func1(){
	static int sv2 = 1; //���� ���� - �Լ� �ȿ� ����. ��ȿ������ �Լ� ����
	int lv = 1; //�������� 
	
	printf("func1() - sv2=%d, lv=%d\n",sv2++,lv++);
} 

void func2(){
	sv=100;
	printf("func2() - sv=%d\n",sv);
//	printf("func2() - sv2=%d\n",sv2); //����. �������� sv2�� ��ȿ���� ����. 
}

int main(void){
	func1();
	func1();
	func1();
	func2();
	
	return 0;
}
