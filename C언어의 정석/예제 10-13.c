#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(void){
	int i;
	
	srand((unsigned)time(NULL)); //������ ���Ѱ�(seed)�� ���� �ð����� �ʱ�ȭ
	printf("time=%u\n",(unsigned)time(NULL));
	
	for(i=0;i<10;i++)
		printf("%d ",rand());
	printf("\n\n");
	
	srand((unsigned)time(NULL)); //������ ���Ѱ�(seed)�� ���� �ð����� �ʱ�ȭ
	printf("time=%u\n",(unsigned)time(NULL));
	
	for(i=0;i<10;i++)
		printf("%d ",rand());
	printf("\n\n");
	
	return 0;
}
