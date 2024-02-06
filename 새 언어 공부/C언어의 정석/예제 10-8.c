#include<stdio.h>

int isLeapYear(int year); //������ year�� ����(leap year0�̸� 1, �ƴϸ� 0�� ��ȯ
int dateToDay(int year, int month, int day); //������ ��¥(�����)�� �� ������ ��ȯ
int main(void){
	int year=2016;
	int month=4;
	
	int sDay= dateToDay(year, month, 1);
	int eDay= dateToDay(year, month+1, 1); //�������� 1��
	int yoil=0; //1���� ���� 
	int i; 
	
	printf("	%4d�� %2d��\n",year, month);
	printf(" SU MO TU WE TH FR SA\n");
	
	yoil=sDay%7; //1���� ���� ���
	
	for(i=0;i<yoil;i++)
		printf("   "); //1�� �տ� ���� ���.
	
	for(i=1;i<=eDay-sDay;i++){
		printf(" %2d",i);
		if((i+yoil)%7==0) printf("\n"); //��¥�� 7�� ����� �Ŀ� �ٹٲ� 
	} 
	printf("\n");
	
	return 0; 
} 

int isLeapYear(int year){
	return ((year%4==0)&&(year%100!=0)||(year%400==0));
}

int dateToDay(int year,int month, int day){
	int endDayOfMon[]={31,28,31,30,31,30,31,31,30,31,30,31};
	int numOfLeapYear=0; //����� ��
	int daySumToLastYear=0; //1�� 1�� 1�Ϻ��� ���⵵������ �ϼ�
	int daySumToLastMonth=0; //�ش� �⵵�� 1�� 1�Ϻ��� ���ޱ����� �ϼ�
	int i;
	
	for(i=0;i<year;i++)
		if(isLeapYear(i))
			numOfLeapYear++;
	
	//���⵵������ �ϼ��� ���Ѵ�
	daySumToLastYear=(year-1)*365+numOfLeapYear; 
	
	if(month>2&&isLeapYear(year))
		endDayOfMon[1]++; //2���� ������ ���� 1 ���� 
	
	//�ش� �⵵�� ���������� �ϼ� ���
	for(i=0;i<month-1;i++)
		daySumToLastMonth += endDayOfMon[i];
		
	return daySumToLastYear + daySumToLastMonth + day;
}
