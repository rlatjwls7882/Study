#include<stdio.h>
int main(){
	int score[5];
	int i, tmp;
	int k = 1;
	
	score[0] = 50;
	score[1] = 60;
	score[k+1] = 70; //score[2] = 70
	score[3] = 80;
	score[4] = 90;
	
	tmp = score[k+2] + score[4]; //tmp = score[3] + score[4]
	
	//for������ �迭�� ��� ��Ҹ� ����Ѵ�.
	for(i=0;i<5;i++) printf("score[%d]:%d\n",i,score[i]);
	
	printf("tmp:%d\n", tmp);
	printf("score[%d]:%d\n",7,score[7]);
	printf("score[%d]:%d\n",-2,score[-2]);
	
	return 0; 
} 
