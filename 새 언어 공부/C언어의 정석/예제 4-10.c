#include<stdio.h>

int main(){
	int score;
	int grade = ' ';
	
	printf("����� ������ �Է��ϼ���.(1~100)>");
	scanf("%d",&score);
	
	switch(score/10){
		case 10:
		case 9:
			grade = 'A';
			break;
		case 8:
			grade = 'B';
			break;
		case 7:
			grade = 'C';
			break;
		case 6:
			grade = 'D';
			break;
		default:
			grade='F';
	}
	
	printf("����� ������ %c�Դϴ�. \n",grade);
	
	return 0;
}
