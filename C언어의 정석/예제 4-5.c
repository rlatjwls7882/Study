#include<stdio.h>

int main(){
	int score;
	char grade;
	char opt = '0';
	 
	printf("������ �Է��ϼ���.>");
	scanf("%d",&score);
	printf("����� ������ %d�Դϴ�.\n",score);
	
	if(score >= 90){ // score�� 90������ ���ų� ũ�� A����(grade) 
		grade='A';
		if(score >=98) opt='+'; //90�� �̻� �߿����� 98�� �̻��� A+ 
		else if(score<94) opt='-'; //90�� �̻� �߿����� 94�� �̸��� A- 
	} 
	else if(score >= 80){ // score�� 80������ ���ų� ũ�� B����(grade) 
		grade='B';
		if(score >=88) opt='+'; //80�� �̻� �߿����� 88�� �̻��� B+ 
		else if(score<84) opt='-'; //80�� �̻� �߿����� 84�� �̸��� B- 
	} 
	else grade='C'; // �������� C����(grade) 
	
	printf("����� ������ %c%c�Դϴ�.",grade,opt);
	
	return 0; 
}
