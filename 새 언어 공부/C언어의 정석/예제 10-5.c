#include<stdio.h>

typedef struct{int hour,min,sec;} myTime;

int timeToSec(myTime t);
myTime secToTime(int sec);

int main(void){
	myTime t=secToTime(45296);
	
	printf("%d�ð� %d�� %d��\n",t.hour,t.min,t.sec);
	printf("%d��",timeToSec(t));
	return 0;
}

myTime secToTime(int sec){
	myTime t;
	t.hour=sec/3600;
	t.min=(sec%3600)/60;
	t.sec=sec%60;
	
	return t;
}

int timeToSec(myTime t){
	return t.hour*3600+t.min*60+t.sec;
}
