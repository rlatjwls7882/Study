#include<stdio.h>
#include<string.h>

struct date{
	int year, mon, day;
};

struct userScore{
	char userId[8];			//����� id
	int score;				//����
	int rank;		 		//���
	struct date inputDate;	//�Է�(input) ��¥
	struct date changeDate;	//����(change) ��¥ 
};

int main(void){
	struct userScore s1={ "myId", 100, 1,{ 2016, 1, 31 },{ 2016, 2, 2 } };
	struct date d1={2016, 3, 3};
	
	strcpy(s1.userId,"yourId");
	
	s1.inputDate.year=1999;
	s1.inputDate.mon=12;
	s1.inputDate.day=31;
	
	s1.changeDate=d1; //��ø�� ����ü�� ��°�� ����
	
	printf("userId=%s\n", s1.userId);
	printf("score=%d\n", s1.score);
	printf("rank=%d\n", s1.rank); 
	printf("inputdate.year=%d\n", s1.inputDate.year);
	printf("inputdate.mon=%d\n", s1.inputDate.mon);
	printf("inputdate.day=%d\n", s1.inputDate.day);
	printf("changedate.year=%d\n", s1.changeDate.year);
	printf("changedate.mon=%d\n", s1.changeDate.mon);
	printf("changedate.day=%d\n", s1.changeDate.day);
	
	return 0;
} 
