#include<stdio.h>
int main(){
	int month;
	
	printf("���� ���� �Է��ϼ���.>");
	scanf("%d",&month); //�Է¹��� ���� month�� �����Ѵ�. 
	
	switch(month){
		case 3: case 4: case 5:
			printf("������ ������ ���Դϴ�.\n");
			break;
		case 6: case 7: case 8:
			printf("������ ������ �����Դϴ�.\n");
			break;
		case 9: case 10: case 11:
			printf("������ ������ �����Դϴ�.\n");
			break;
//		case 12: case 1: case 2:
		default:
			printf("������ ������ �ܿ��Դϴ�.\n");
	}
	
	return 0;
}
