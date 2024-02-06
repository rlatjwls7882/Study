#include<stdio.h>
#include<time.h>

// �� ��¥�� ���̸� ��ȯ�ϴ� �Լ�
time_t timeDiff(int y1,int m1,int d1,int y2,int m2,int d2);
int getYoil(int y,int m,int d); //������ ��¥�� ������ ��ȯ(0~6), 0�� �Ͽ���
 
int main(void){
	char* yoil[]={"��","��","ȭ","��","��","��","��"};
	const int DAY_IN_SEC = 60*60*24;
	
	time_t now=time(NULL);
	time_t morae=now+DAY_IN_SEC; //���ú��� 1�� �ĸ� ��� 
	
	struct tm today, tomorrow;
	struct tm* tmp=localtime(&now); //time_t�� struct tm���� ��ȯ
	today=*tmp;
	 
	tmp=localtime(&morae);
	tomorrow=*tmp;
	
	printf("now=%lld\n",now); //ex)now=1460639891
	printf("������ %4d�� %2d�� %2d�� �Դϴ�.\n",today.tm_year+1900,today.tm_mon+1,today.tm_mday);
	printf("������ %4d�� %2d�� %2d�� �Դϴ�.\n",tomorrow.tm_year+1900,tomorrow.tm_mon+1,tomorrow.tm_mday);
	
	time_t diff=timeDiff(2001,1,1,2016,4,15);
	
	printf("2001/01/01�� 2016/04/15�� ���̴� %lld��(%lld��)\n",diff,diff/DAY_IN_SEC);
	printf("%d/%2d/%2d�� %s�����Դϴ�.\n",1999,12,31,yoil[getYoil(1999,12,31)]);
	
	return 0;
} 

int getYoil(int y,int m,int d){
	struct tm dt={0};
	
	dt.tm_year=y-1900;
	dt.tm_mon=m-1;
	dt.tm_mday=d;
	
	mktime(&dt); //����� �ʵ�κ��� ������ �ʵ�(tm_wday, tm_yday)�� ����ؼ� ä��.
	
	return dt.tm_wday; 
}

time_t timeDiff(int y1,int m1,int d1,int y2,int m2,int d2){
	struct tm dt1={0}, dt2={0}; //��� �ʵ带 0���� �ʱ�ȭ
	time_t t1,t2; 
	
	dt1.tm_year= y1-1900;
	dt1.tm_mon= m1-1;
	dt1.tm_mday= d1;
	
	dt2.tm_year= y2-1900;
	dt2.tm_mon= m2-1;
	dt2.tm_mday= d2;
	
	t1=mktime(&dt1); //����ü�� �ʵ���� �ð��� ����ؼ� ��ȯ 
	t2=mktime(&dt2); //struct tm�� time_t�� ��ȯ 
	
	return difftime(t2,t1);
//	return (time_t)(t2-t1);
}
