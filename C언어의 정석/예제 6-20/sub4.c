#include<stdio.h>

extern int gv; //������ ����. ���� ������ ��쵵 ������ �������� �ʴ� ���� ��Ģ

void gfunc(void); //���� �Լ��� ���� extern�� ������. ��ü���� ��밡��
static void sfunc(void); //����(static) �Լ��� ����. �ҽ�����(sub4.c)�������� ��밡�� 

static void sfunc(void){ //����(static) �Լ��� ����. �ҽ�����(sub4.c) �������� ��밡�� 
	printf("sfunc() - sub4.c\n");
	gv=200;
}

void gfunc(void){ //���� �Լ��� ����. extern�� ������. ��ü���� ��밡�� 
	sfunc();
	printf("gfunc(%d)\n",gv);
}
