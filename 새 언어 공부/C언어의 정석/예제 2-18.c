#include<stdio.h>
#include<float.h> // FLT_MIN, FLT_MAX���� ����ϱ� ���� �߰� 

int main(){
	float f1 = FLT_MAX + 1000;
	float f2 = FLT_MAX + 1e32f; //FLT_MAX�� 10������ ���Ѵ�. 
	
	float f3 = FLT_MIN * 0.1f; 
	float f4 = 1e-45f; // floatŸ���� ���� ���� �ּҰ� 
	float f5 = 1e-45f * 0.1f;
	
	printf("FLT_MAX =%e\n", FLT_MAX);
	printf("FLT_MAX+1000 =%e\n", f1);
	printf("FLT_MAX+1e32 =%e\n\n", f2);
	
	printf("FLT_MIN =%e\n", FLT_MIN);
	printf("FLT_MIN*0.1 =%e\n", f3);
	printf("1e-45 =%e\n", f4);
	printf("1e-45*0.1 =%e\n", f5);
	
	return 0; 
}
