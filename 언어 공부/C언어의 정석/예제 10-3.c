#include<stdio.h>
#include<time.h>

int main(void){
	char* yoil[]={"��","��","ȭ","��","��","��","��"};
	
	time_t now=time(NULL);
	struct tm* lt=localtime(&now); //time_t�� struct tm���� ��ȯ
	
	printf("now=%d\n",now);
	printf("%s",asctime(lt)); //asctime()�� ����� ���๮�ڰ� ���ԵǾ� ����.
	printf("%4d�� %2d�� %2d�� %s����\n",lt->tm_year+1900,lt->tm_mon+2,lt->tm_mday,yoil[lt->tm_wday]); 
	printf("%2d�� %2d�� %2d��\n",lt->tm_hour,lt->tm_min,lt->tm_sec);
	printf("������ %d��°��\n",lt->tm_yday);
	
	return 0;
} 
