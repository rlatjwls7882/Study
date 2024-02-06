#include<stdio.h>
#include<time.h>

int main(void){
	time_t now;
	char dtStr[100];
	struct tm* dt;
	
	now=time(NULL);
	dt=localtime(&now);
	
	printf("%s",asctime(dt));
	printf("%s",ctime(&now));
	
	printf("%s\n",_strdate(dtStr));
	printf("%s\n",_strtime(dtStr));
	
	strftime(dtStr, 100, "%Y/%m/%d",dt); printf("%%Y/%%m/%%d=%s\n",dtStr);
	strftime(dtStr, 100, "%H/%M/%S",dt); printf("%%H/%%M/%%S=%s\n",dtStr);
	strftime(dtStr, 100, "%j",dt); printf("������ ������ %s��° ��\n",dtStr);
	strftime(dtStr, 100, "%U",dt); printf("������ ������ %s��° ��\n",dtStr);
	
	return 0;
}
