#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	int num1, num2;
	int sum=0;
	
	srand((unsigned)time(NULL)); //������ �ʱ�ȭ 
	
	roll_again:
	num1 = rand()%6+1; //1~6 ������ ������ ���� �� num1�� ���� 
	num2 = rand()%6+1;
	
	printf("num1=%d, num2=%d\n",num1,num2);
	
	sum +=num1 + num2;
	
	if(num1==num2) goto roll_again; //num1�� num2�� ���� ������ roll_again�̶� �̸��� ���̺�� �̵�
	
	printf("sum=%d\n",sum);
	
	return 0; 
}
