#include<stdio.h>

int isLeapYear(int year); //������ year�� ����(leap year0�̸� 1, �ƴϸ� 0�� ��ȯ
int dateToDay(int year, int month, int day); //������ ��¥(�����)�� �� ������ ��ȯ
int main(void){
	char * week_day[]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
	
	int year=2016, month=4, day=1;
	int totalDay=dateToDay(year,month,day);
	
	//�� ��¥�� ���̸� ��(day) ������ ���Ѵ�.
	int dayDiff=dateToDay(2016,2,28)-dateToDay(2016,3,2);
	
	printf("year=%d, month=%d, day=%d\n",year,month,day);
	printf("totalDay=%d\n",totalDay);
	printf("%d.%d.%d is %sDAY\n",year,month,day,week_day[totalDay%7]);
	printf("2016.2.28 - 2016.3.2 = %d\n",dayDiff);
	
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
