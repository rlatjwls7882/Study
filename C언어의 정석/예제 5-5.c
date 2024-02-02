#include<stdio.h>
#include<string.h> //memcpy(), memcmp()�� ����ϱ� ���� �߰�

int main(){
	int arr1[] = {2, 3, 5, 7};
	int arr2[sizeof(arr1)/sizeof(arr1[0])];
	int arr3[sizeof(arr1)/sizeof(arr1[0])];
	
	const int LEN = sizeof(arr1)/sizeof(arr1[0]);
	int i;
	int chk = 0; // �� �迭�� ������ Ȯ���ϱ� ���� ����. 0�̸� ����, 1�̸� �ٸ�.
	
	memcpy(arr2,arr1,sizeof(arr1)); //�迭 arr1 ��ü�� �迭 arr2�� ����
	memcpy(arr3,arr1,sizeof(arr1)); //�迭 arr1 ��ü�� �迭 arr3�� ����
	 
	arr2[0] = 100; //�迭 arr2�� ù ��° ����� ���� ����
	
	for(i=0;i<LEN;i++) printf("arr1[%d]=%d \t arr2[%d]=%d \t arr3[%d]=%d \n",i,arr1[i],i,arr2[i],i,arr3[i]);
	
	chk = memcmp(arr2, arr1, sizeof(arr1));
	
	if(!chk) /*if(chk==0) */ printf("arr1�� arr2�� �����ϴ�.\n");
	else printf("arr1�� arr2�� �ٸ��ϴ�.\n"); 
	
	chk = memcmp(arr3, arr1, sizeof(arr1));
	
	if(!chk) /*if(chk==0) */ printf("arr1�� arr3�� �����ϴ�.\n");
	else printf("arr1�� arr3�� �ٸ��ϴ�.\n"); 
	
	return 0; 
} 
