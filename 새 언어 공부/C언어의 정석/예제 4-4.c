#include<stdio.h>

int main(){
	int score; //������ �����ϱ� ���� ����
	char grade = ' '; //������ �����ϱ� ���� ����. �������� �ʱ�ȭ�Ѵ�.
	
	printf("������ �Է��ϼ���.>");
	scanf("%d",&score);
	
	if(score >= 90) grade='A'; // score�� 90������ ���ų� ũ�� A���� 
	else if(score >= 80) grade='B'; // score�� 80������ ���ų� ũ�� B����
	else if(score >= 70) grade='C'; // score�� 70������ ���ų� ũ�� D����
	else grade='D'; // �������� D����
	
	printf("����� ������ %c�Դϴ�.",grade);
	
	return 0; 
}
