#include<stdio.h>

int main(void){
	const int MAX = 999;
	int i = 100;
	
	const int* pci; //��� ������ pci ����-�����Ͱ� ����Ű�� ����� ���
	int *ptr;
	
	const int* const PCI = &MAX; //��� ������ ��� PCI����. ���� ������ ��� ���
	      int* const PTR = &i; //������ ��� PTR����-�����Ͱ� ���
	
	printf("MAX=%d\n",MAX);
	printf("i=%d\n",i);
	
	//������ pci�� ptr�� ���� i�� ����Ű�� �Ѵ�
	pci = &MAX;
	ptr = (int*)&MAX; //����ȯ�� ������� ��� �߻����� ����.
//	*pci = 666; //����. pci Ÿ���� 'const int*'�� ����Ұ�
 	*ptr = 666; //OK. ptr�� ����Ű�� Ÿ���� ����̾ ���氡��
	 
	//������ pci�� ptr�� ���� i�� ����Ű�� �Ѵ�.
	pci = &i;
	ptr = &i;
//	*pci = 200; //����. pci�� Ÿ����  'const int*'�� ����Ű�� ����� ������ ����Ұ�
	*ptr = 200; //OK.
	printf("MAX=%d\n",MAX);
	printf("i=%d\n",i);
	
//	PCI = &i; //����. ��� ������ ����� �� ����Ұ�
//	*PCI = 300; //����. PCI�� ����Ű�� ����� ���� i�ε��� ����Ұ�
//	PTR = &i; //����. ������ ����� �� ����Ұ�
	*PTR = 300; //OK. ������ ����� ����Ű�� ����� ���氡�� 
	printf("MAX=%d\n",MAX);
	printf("i=%d\n",i);
	return 0;
}
