#include<stdio.h>

int main(void){
	int ch;
	
	do{
		printf("���� �ϳ��� �Է��ϼ���.\n");
		ch=getche(); //Ű�� ������ �ٷ� �Էµ� 
		
		printf("�Է��Ͻ� ���ڴ� '%c'�Դϴ�.\n",ch);
		
	} while(ch!='x'&&ch!='X'); //'x' �Ǵ� 'X'�� �Է��ϸ� �ݺ� ����
	
	printf("'%c'�� �Է��ϼż� ����Ǿ����ϴ�.\n",ch);
	
	return 0; 
}
