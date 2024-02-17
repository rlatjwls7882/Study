#include<stdio.h>

void sort(const int* src,int* rtn,int len){
	int i,j,tmp;
	const int LEN = len;
	int* ptr=rtn;
	
	while(len--)
		*ptr++ = *src++; //�迭 src�� ��� ��Ҹ� �迭 rtn���� ����
	
	//�迭 rtn�� �����Ѵ�.
	for(i=0;i<LEN-1;i++)
		for(j=0;j<LEN-1-i;j++)
			if(rtn[j]>rtn[j+1]){
				tmp=rtn[j];
				rtn[j]=rtn[j+1];
				rtn[j+1]=tmp;
			} 
}

void printArr(const int arr[],int len){
	printf("[");
	while(len--) printf("%d ",*arr++);
	printf("]\n");
}
int main(void){
	int src[]={6,7,2,9,1,3,4};
	int rtn[7]; //���İ���� ���� �迭
	
	sort(src,rtn,7); //������ �迭�� ���İ���� ������ �迭�� �Ѱ��ش�
	printArr(src,7); //�����ϱ� �� �迭�� ���
	printArr(rtn,7); //���ĵ� �迭�� ���
	
	return 0; 
} 
