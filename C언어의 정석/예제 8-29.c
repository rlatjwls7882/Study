#include<stdio.h>
#include<stdlib.h> //qsort()
#include<time.h>
#define SIZE 100
int intArr[SIZE];

float performanceTest(void(*pf)(void), unsigned n); //�Լ��� n�� ������ �ð� ����
void repeat(void(*pf)(void), unsigned n); //������ �Լ�(pf)�� nȸ �ݺ�
void fillArr(void); //�迭�� ������ ���� ä��
int compareInt(const void* v1,const void* v2); //qsort()�� ����� ���Լ�

void qsortCall(void); //qsort()�� ȣ���ϴ� �Լ�
void bubbleSort(void); //�������� �Լ�

int main(void){
	float time1, time2;
	
	fillArr(); //�迭�� ������ ���� ä���.
	
	time1=performanceTest(qsortCall, 100); //������ 100ȸ�� �ɸ� �ð� ����
	time2=performanceTest(bubbleSort, 100); //���� ���� 100ȸ�� �ɸ� �ð�����
	
	printf("time1(quick sort)= %f\n",time1);
	printf("time2(bubble sort)= %f\n",time2);
	
	return 0; 
} 

void fillArr(void){
	int i;
	srand(time(NULL));
	
	for(i=0;i<SIZE;i++)
		intArr[i]=rand()%10;
}

float performanceTest(void(*pf)(void), unsigned n){
	clock_t start, end;
	start=clock();
	repeat(pf,n);
	end-clock();
	
	return (end-start)/(float)CLOCKS_PER_SEC;
}

void repeat(void(*pf)(void),unsigned n){
	while(n--)
		pf();
}

int compareInt(const void* v1,const void* v2){
	return *(int*)v1 - *(int*)v2;
}

void qsortCall(void){
	qsort(intArr,SIZE,sizeof(int),compareInt);
}

void bubbleSort(void){
	int i, j, tmp;
	for(i=0;i<SIZE;i++)
		for(j=0;j<SIZE-i-1;j++)
			if(intArr[j]>intArr[j+1]){
				tmp=intArr[j];
				intArr[j]=intArr[j+1];
				intArr[j+1]=tmp;
			}
}
