#include<stdio.h>

int main(void){
	int arr[]={0,1,2,3,4};
	int *ptr = &arr[0];
	const int LEN = sizeof(arr)/sizeof(arr[0]);
	int i;
	
	//�������� ���� 1�� ������Ű�鼭 ���
	for(i=0;i<LEN;i++) printf("ptr++=%p, &arr[%d]=%p\n",ptr++,i,&arr[i]);
	puts(""); //�ٹٲ�
	
	ptr = &arr[0]; //������ ptr�� ���� �ٲ�����Ƿ� �ٽ� �ʱ�ȭ
	 
	//�����ͷ� �迭�� ��� ��Ҹ� ���
	for(i=0;i<LEN;i++) printf("ptr++=%d, &arr[%d]=%d\n",*ptr++,i,arr[i]);
	
	return 0;
}
