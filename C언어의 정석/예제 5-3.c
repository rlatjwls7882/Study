#include<stdio.h>

int main(){
	int arr[5] = {50, 60, 70, 80, 90};
	int arr2[5] = {0}; //�迭 arr2�� ��� ��Ҹ� 0���� �ʱ�ȭ
	int arr3[5];
	
	int i;
	
	//�迭 arr3�� �� ��Ҹ� 1,2,3,4,5�� �ʱ�ȭ
	for(i=0;i<5;i++) arr3[i] = i+1;
	
	for(i=0;i<5;i++) printf("arr[%d]=%d\n", i, arr[i]);
	for(i=0;i<5;i++) printf("arr2[%d]=%d\n", i, arr2[i]);
	for(i=0;i<5;i++) printf("arr3[%d]=%d\n", i, arr3[i]);
	
	return 0;
} 
