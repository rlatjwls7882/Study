#include<stdio.h>
#include<math.h>

void printResult(double d){
	printf("ceil(%3.1f)=%3.1f	",d,ceil(d)); //�ø�
	printf("floor(%3.1f)=%3.1f  	",d,floor(d)); //����
	printf("round(%3.1f)=%3.1f  	",d,round(d)); //�ݿø�
	printf("trunc(%3.1f)=%3.1f\n",d,trunc(d)); //�Ҽ��� ���� ���� 
}

double roundn(double d,int n){ //d�� �Ҽ��� n°�ڸ����� �ݿø� 
	return round(d*pow(10,n-1))/pow(10,n-1);
}

int main(void){
	printResult(1.4);
	printResult(1.5);
	printResult(1.6);
	printResult(-1.4);
	printResult(-1.5);
	printResult(-1.6);
	
	printf("%g\n",roundn(1234.567,1));
	printf("%g\n",roundn(1234.567,2));
	printf("%g\n",roundn(1234.567,3));
	
	return 0;
} 
