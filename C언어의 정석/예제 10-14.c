#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define RECORD_NUM 5
#define TABLE_NAME "TEST_TABLE"

char* getRandArr(char* arr[],int LEN);
int getRand(int from, int to);

int main(void){
	char* CODE1[]={"010","011","017","018","019"};
	char* CODE2[]={"����","����"};
	char* CODE3[]={"10��","20��","30��","40��","50��"};
	int i;
	
	srand((unsigned)time(NULL));
	
	for(i=0;i<RECORD_NUM;i++){
		printf("INSERT INTO %s VALUES ('%s', '%s', '%s', %d);\n",TABLE_NAME,getRandArr(CODE1,5),getRandArr(CODE2,2),getRandArr(CODE3,5),getRand(1,6));
	} 
	
	return 0;
}

char* getRandArr(char* arr[],const int LEN){
	return arr[getRand(0,LEN)]; //�迭�� ����� �� �� �ϳ��� ��ȯ�Ѵ� 
}

int getRand(int from, int to){ //to�� ������ �ȵ� 
	return rand()%(to-from)+from;
}
