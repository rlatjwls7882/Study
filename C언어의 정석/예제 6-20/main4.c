#include <stdio.h>

int gv=100; //������ ����. extern�� ���� �� �ִ� ��쵵 ������ ������ �ʴ� ���� ��Ģ

void gfunc(void); // ���� �Լ��� ����. extern�� ������. sub4.c�� ���ǵ�� ����
static void sfunc(void); //���� �Լ��� ����. �ҽ�����(main4.c) �������� ��밡��

extern int main(void){
	gfunc(); //sub4.c�� gfunc()�� ȣ��
	sfunc(); //main4.c�� sfunc()�� ȣ��
	return 0; 
} 
static void sfunc(void) { //���� �Լ��� ����. �ҽ�����(main4.c) �������� ��밡�� 
	printf("sfunc() - main4.c\n");
}
