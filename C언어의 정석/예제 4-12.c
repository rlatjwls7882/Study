#include<stdio.h>

int main(){
	char gender;
	char regNo[15]; // ���ڿ��� ������ ������ ���ڿ��� ���̺��� 1�� Ŀ�� �Ѵ�.
	
	printf("����� �ֹι�ȣ�� �Է��ϼ���.(011231-1111222)>");
	scanf("%s",regNo); //�ֹι�ȣ�� �Է¹޴´�.
	
	gender = regNo[7]; //�Է¹��� �ֹε�Ϲ�ȣ�� 8��° ���ڸ� ��´� 
	
	switch(gender){
		case '1':
		case '3':
			switch(gender){
				case '1':
					printf("����� 2000�� ������ ����� �����Դϴ�.\n");
					break;
				case '3':
					printf("����� 2000�� ���Ŀ� ����� �����Դϴ�.\n");
			} 
			break; //�� break���� ������ �ʵ��� ���� 
		case '2':
		case '4':
			switch(gender){
				case '2':
					printf("����� 2000�� ������ ����� �����Դϴ�.\n");
					break;
				case '4':
					printf("����� 2000�� ���Ŀ� ����� �����Դϴ�.\n");
					break;
			} 
			break;
		default:
			printf("��ȿ���� ���� �ֹε�Ϲ�ȣ�Դϴ�.\n");
	} 
	
	return 0;
}
