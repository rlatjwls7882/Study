#include<stdio.h>

int main(void){
	printf("�ֱ� ���� �ð�=%s\n",__TIMESTAMP__);
	printf("�����ϵ� ��¥=%s\n",__DATE__);
	printf("�����ϵ� �ð�=%s\n",__TIME__);
	printf("�����̸�=%s\n",__FILE__);
	printf("���ι�ȣ=%d\n",__LINE__); //�ҽ������� 8��° �� 
	
	return 0;
}
