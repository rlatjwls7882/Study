#include<stdio.h>

int main(){
	char gender;
	char regNo[15]; // ���ڿ��� ������ ������ ���ڿ��� ���̺��� 1�� Ŀ�� �Ѵ�.
	
	printf("����� �ֹι�ȣ�� �Է��ϼ���.(011231-1111222)>");
	scanf("%s",regNo); //�ֹι�ȣ�� �Է¹޴´�.
	
	gender = regNo[7]; //�Է¹��� �ֹε�Ϲ�ȣ�� 8��° ���ڸ� gender�� ����
	
	switch(gender){
		case '1':
		case '3':
			printf("����� �����Դϴ�.\n");
			break;
			
		case '2':
		case '4':
			printf("����� �����Դϴ�.\n");
			break;
			
		default:
			printf("��ȿ���� ���� �ֹε�Ϲ�ȣ�Դϴ�.\n");
	} 
	
	return 0;
}
