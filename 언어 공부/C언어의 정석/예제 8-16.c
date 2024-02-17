#include<stdio.h>
#include<stdlib.h>

int main(void){
	int arr[]={1,2,3,4,5}; //�ڵ��Ҵ�
	const int LEN = sizeof(arr)/sizeof(arr[0]);
	
	int* p = (int*)malloc(sizeof(arr)); //�����Ҵ�. �迭  arr�� ���� ũ�� �Ҵ�
	int i;
	
	if(p==NULL){ //���Ҵ翡 �����ߴ��� Ȯ��
		printf("out of memory\n");
		exit(1); //������������ ���α׷� ���� 
	} 
	
	for(i=0;i<LEN;i++){
		p[i]=arr[i]*10;
		printf("arr[%d]=%d, p[%d]=%d\n",i,arr[i],i,p[i]);
	}
	
	return 0;
}
