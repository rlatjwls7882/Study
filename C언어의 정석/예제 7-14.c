#include<stdio.h>

int main(void){
	int arr[4] = {0,1,2,3};
	int *ptr=&arr[0];
	int *ptr2;
	int sum=0;
	
	ptr2=ptr; // ptr�� ���� ptr2�� ����. ���� ptr2�� �迭 arr�� ����Ű�� �ȴ�.
	
	printf("ptr=%p\n",ptr);
	printf("ptr2=%p\n",ptr2);
	
	if(ptr==ptr2) printf("ptr�� ptr2�� ���� ����� ����ŵ�ϴ�.\n");
	else printf("ptr�� ,ptr2�� �ٸ� ����� ����ŵ�ϴ�.\n");
	
	while(ptr<=&arr[3]) //�迭 arr�� ��� ��Ҹ� ����Ѵ�
		printf("*ptr++=%d\n",*ptr++);
	
	while(ptr2<=&arr[3]) //�迭 arr�� ��� ��Ҹ� ���Ѵ�.
		sum+=*ptr2++;
	
	printf("sum=%d\n",sum);
	
	return 0; 
} 
