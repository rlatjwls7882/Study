#include<stdio.h>
int main(void){
	int i=0x1B2B3B4B;
	int *pi=&i;
	char *pc=(char*)pi; //�������� Ÿ���� char*�� ����ȯ�� ������ pc�� ���� 
	short *ps=(short*)pi;
	
	printf("&i=%p\n",&i);
	printf("pi=%p\n",pi);
	printf("pc=%p\n",pc);
	printf("ps=%p\n",ps);
	
	printf("*pi=%X\n",*pi); //������ pi�� ����Ű�� ��(i)�� 16����(%X)�� ��� 
	printf("*pc=%X\n",*pc);
	printf("*ps=%X\n",*ps);
	printf("*(int*)pi=%X\n",*(int*)pi);
	return 0;
}
