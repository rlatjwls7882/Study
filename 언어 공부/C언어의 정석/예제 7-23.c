#include<stdio.h>

int main(void){
	int arr2[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};
	int arr[sizeof(arr2)/sizeof(arr2[0][0])]; //arr2�� ���� ũ���� 1���� �迭
	
	const int LEN = sizeof(arr2)/sizeof(arr2[0][0]);
	int len = LEN;
	int i;
	
	int *ptr = arr;
	int *ptr2 = (int*)arr2;
	
	while(len--)
		*ptr++ = *ptr2++; //�迭 arr2�� ������ �ϳ��� �迭 arr�� ���� 
	
	for(i=0;i<LEN;i++)
		printf("arr[%d]=%d \t arr2[%d][%d]=%d\n",i,arr[i],i/4,i%4,arr2[i/4][i%4]); //P.224�� ���� 
	return 0;
}
