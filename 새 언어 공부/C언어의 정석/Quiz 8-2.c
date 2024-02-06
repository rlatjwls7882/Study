#include<stdio.h>

int sumArr(int arr[],int len); //�迭�� ��� ����� ���� ��ȯ
void printArr(int arr[],int len); //�迭�� ��� ��Ҹ� ���
int maxArr(int arr[],int len); //�迭�� ��� ����� �ִ밪�� ��ȯ
 
int main(void){
	int arr[]={1,2,3,4,5};
	const int LEN = sizeof(arr)/sizeof(arr[0]);
	
	int sum = sumArr(arr,LEN);
	
	printArr(arr,LEN);
	printf("sum=%d\n",sum);
	printf("max=%d\n",maxArr(arr,LEN));
	return 0;
} 

int sumArr(int arr[],int len){ //int sumArr(int* Arr,int len)
	int sum=0;
	
	while(len--)
		sum +=*arr++; // �迭�� ��� ���� sum�� �����Ѵ�.
		
	return sum; 
}

void printArr(int arr[],int len){ //void printArr(int *arr,int len)
	int i;
	
	for(i=0;i<len;i++)
		printf("arr[%d]=%d\n",i,arr[i]);
}

int maxArr(int arr[],int len){
	int max=0;
	
	while(len--){
		if(*arr>max) max=*arr;
		*arr++;	
	}
		
	return max;
}
