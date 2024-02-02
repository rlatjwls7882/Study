#include<stdio.h>

int main(void){
	const int MAX = 999;
	int i = 100;
	
	const int* pci; //상수 포인터 pci 선언-포인터가 가리키는 대상이 상수
	int *ptr;
	
	const int* const PCI = &MAX; //상수 포인터 상수 PCI선언. 대상과 포인터 모두 상수
	      int* const PTR = &i; //포인터 상수 PTR선언-포인터가 상수
	
	printf("MAX=%d\n",MAX);
	printf("i=%d\n",i);
	
	//포인터 pci와 ptr이 변수 i를 가리키게 한다
	pci = &MAX;
	ptr = (int*)&MAX; //형변환을 적어줘야 경고가 발생하지 않음.
//	*pci = 666; //에러. pci 타입이 'const int*'라서 변경불가
 	*ptr = 666; //OK. ptr이 가리키는 타입이 상수이어도 변경가능
	 
	//포인터 pci와 ptr이 변수 i를 가리키게 한다.
	pci = &i;
	ptr = &i;
//	*pci = 200; //에러. pci의 타입이  'const int*'라서 가리키는 대상이 변수라도 변경불가
	*ptr = 200; //OK.
	printf("MAX=%d\n",MAX);
	printf("i=%d\n",i);
	
//	PCI = &i; //에러. 상수 포인터 상수의 값 변경불가
//	*PCI = 300; //에러. PCI가 가리키는 대상이 변수 i인데도 변경불가
//	PTR = &i; //에러. 포인터 상수의 값 변경불가
	*PTR = 300; //OK. 포인터 상수가 가리키는 대상은 변경가능 
	printf("MAX=%d\n",MAX);
	printf("i=%d\n",i);
	return 0;
}
