#include<stdio.h>
#pragma warning(disable:4996) // ��ü �Լ��� ����϶�� ��� ���� �� ��� 
int main(){
	float f;
	double d;
	
	printf("�� ���� �Ǽ��� �Է����ּ���>");
	scanf("%f%lf", &f, &d); //�� ������ ������ ������ �־ �ǰ� ��� �ȴ�.
	
	printf("�Է��Ͻ� �Ǽ��� %f�Դϴ�.\n", f);
	printf("�Է��Ͻ� �Ǽ��� %f�Դϴ�.\n", d);
	
	return 0; 
}
