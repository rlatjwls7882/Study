#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
	int numArr[10];
	const int LEN = sizeof(numArr) / sizeof(numArr[0]);
	int i, n, tmp;
	
	srand((unsigned)time(NULL));
	
	for(i=0;i<LEN;i++){
		numArr[i] = i; //�迭�� 0~9�� ���ڷ� �ʱ�ȭ�Ѵ�. 
		printf("%d",numArr[i]);
	} 
	printf("\n");
	
	for(i=0;i<LEN*2;i++){
		n= rand() % 10; //0~9���� �� ���� ���Ƿ� ��´�. 
		
		tmp = numArr[0];
		numArr[0] = numArr[n];
		numArr[n] = tmp;
	}
	for(i=0;i<LEN;i++) printf("%d",numArr[i]);
	printf("\n");
}
