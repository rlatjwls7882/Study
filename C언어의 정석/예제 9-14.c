#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct custInfo{//������ 
	char custName[20];
	char phoneType; //��ȭ��ȣ ����
	union{
		char homeNo[15]; //������ȭ(��)
		char officeNo[15]; //������ȭ(����)
		char cellNo[15]; //�ڵ��� 
	}; //�̸��� ���� ����ü 
} CustInfo;

void printCustInfoArr(CustInfo arr[],const int LEN);
void printCustInfo(CustInfo c);

int main(void){
	CustInfo cust[]={
		{"CHOI",'H',"02-1234-1234"},
		{"LEE", 'M', "031-1111-2222"},
		{"KIM", 'O', "010-2222-1111"}
	};
	
	const int LEN=sizeof(cust)/sizeof(cust[0]);
	printCustInfoArr(cust,LEN);
	
	return 0;
}

void printCustInfoArr(CustInfo arr[],const int LEN){
	int i;
	for(i=0;i<LEN;i++){
		printCustInfo(arr[i]);
		puts("");
	}
}

void printCustInfo(CustInfo c){
	printf("�̸�:%s\n",c.custName);
	
	switch(c.phoneType){
		case 'H':
			printf("����ȭ:%s\n",c.homeNo);
			break;
		case 'O':
			printf("�繫����ȭ:%s\n",c.officeNo);
			break;
		case 'M':
			printf("�ڵ���:%s\n",c.cellNo);
			break;
	}
}

