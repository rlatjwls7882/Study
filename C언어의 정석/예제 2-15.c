#include<stdio.h>
#include<float.h> // FLT_MIN, FLT_MAX ���� ����ϱ� ���� �߰�

int main(){
	float f = 9.12345678901234567890;
	float f2 = 1.2345678901234567890;
	double d = 9.12345678901234567890;
	long double ld = 9.12345678901234567890;
	
	printf("		1.2345678901234567890\n");
	printf("f :		%f\n", f); // �Ҽ��� ���� 6�ڸ����� ���. (7�ڸ����� �ݿø�)
	printf("f2 :	%24.20f\n",f);  
	printf("d :		%24.20f\n",d);
	printf("ld :	%24.20Lf\n",ld);
	printf("\n");
	printf("float :			%e ~ %e\n", FLT_MIN, FLT_MAX);
	printf("double :		%e ~ %e\n", DBL_MIN, DBL_MAX);
	printf("long double :	%e ~ %e\n", LDBL_MIN, LDBL_MAX);
	
	return 0;
} 
