#include<stdio.h>
#include<locale.h>
#include<string.h>
int main(){
	wchar_t wch=L'��'; // ���� ���, ���ڿ� �տ� 'L'�� �ٿ��� Ȯ�� �������� �˸���.
	
	setlocale(LC_ALL, "Korean"); // ��������. �ѱ��� �ùٸ��� ����ϱ� ���� �ʿ�
	
	wprintf(L"%c\n",wch); 
	
	printf("len=%d\n", strlen("������123")); // �ѱ��� 2 byte�̹Ƿ� 2x3+3=9 
	printf("len=%d\n", wcslen(L"������123")); // �ѱ��� Ȯ�� ���ڷ� �ٷ��.
	
	return 0; 
}
 
