#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
int main(){
	int number[10];
	int counter[10]={0}; //�迭�� ��� ��Ҹ� 0���� �ʱ�ȭ 
	const int LEN = sizeof(number) / sizeof(number[0]);
	int i; 
	
	srand((unsigned)time(NULL));
	
	for(i=0;i<LEN;i++){
		number[i]=rand()%10; //number[i]�� 0~9 ������ ������ ���� ����
		printf("%d",number[i]); 
	}
	printf("\n");
	
	for(i=0;i<LEN;i++) counter[number[i]]++;
	for(i=0;i<LEN;i++) printf("%d�� ���� :%d\n",i,counter[i]);
	
	return 0;
}
