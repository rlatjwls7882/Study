#include<stdio.h>
#include<string.h>

int main(){
	int arr[6] ={1,2,3,4,5,6};
	int arr2[2][3]={0};
	
	const int LEN = sizeof(arr)/sizeof(arr[0]);
	const int COL = sizeof(arr2[0]) / sizeof(arr2[0][0]);
	
	int i;
	
	for(i=0;i<LEN;i++) printf("arr[%d]=%d arr2[%d][%d]=%d\n",i,arr[i],i/COL,i%COL,arr2[i/COL][i%COL]);
	
	if(memcmp(arr,arr2,sizeof(arr))==0) printf("arr�� arr2�� �����ϴ�.\n");
	else printf("arr�� arr2�� �ٸ��ϴ�.\n");
	
	memcpy(arr2,arr,sizeof(arr)); //�迭 arr���� arr2�� sizeof(arr)��ŭ ����
	
	printf("\n= after copying =\n");
	
	for(i=0;i<LEN;i++) printf("arr[%d]=%d arr2[%d][%d]=%d\n",i,arr[i],i/COL,i%COL,arr2[i/COL][i%COL]);
	
	if(memcmp(arr,arr2,sizeof(arr))==0) printf("arr�� arr2�� �����ϴ�.\n");
	else printf("arr�� arr2�� �ٸ��ϴ�.\n");
	
	return 0; 
} 
