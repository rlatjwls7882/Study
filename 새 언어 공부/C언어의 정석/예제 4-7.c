#include<stdio.h>
#include<time.h> //time() �� ����ϱ� ���� �߰�
#include<stdlib.h> //srand(), rand()�� ����ϱ� ���� �߰�

int main(){
	int user, com;
	
	printf("����(1), ����(2), ��(3) �� �ϳ��� �Է��ϼ���.>");
	scanf("%d", &user);
	
	srand((unsigned)time(NULL)); // ���� �ð����� ������ ���Ѱ��� �ʱ�ȭ
	com = rand() % 3 +1; //1,2,3�� �ϳ��� com�� ����� 
	printf("����� %d�Դϴ�.\n",user);
	printf("���� %d�Դϴ�.\n",com);
	
	switch(user-com){
		case 2: case -1:
			printf("����� �����ϴ�.\n");
			break;
		case 1: case -2:
			printf("����� �̰���ϴ�.\n");
			break;
		case 0:
			printf("�����ϴ�.\n");
			break; //������ �����̹Ƿ� break���� ����� �ʿ䰡 ����. 
	} 
	
	return 0;
} 
