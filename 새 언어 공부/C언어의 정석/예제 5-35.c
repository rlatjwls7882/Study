#include<stdio.h>
#define STU 4 //�л� ��
#define SUB 3 //���� ��

int main(){
	int score[STU+1][SUB+1]={
		{100,100,100},
		{25,20,20},
		{35,30,30},
		{45,40,40}
	};
	int i,j;
	
	printf("��ȣ ���� ���� ���� ���� ���\n");
	printf("=========================================\n");
	
	for(i=0;i<STU;i++) {
		printf(" %d  ",i+1);
		
		for(j=0;j<SUB;j++){
			score[i][SUB]+=score[i][j];
			score[STU][j]+=score[i][j];
			printf("%3d  ",score[i][j]);
		}
		// �л��� ������ ����� ���
		printf(" %3d  %5.1f\n",score[i][SUB],score[i][SUB]/(float)SUB); 
	}
	printf("=========================================\n");
	printf("���� ");
	
	for(j=0;j<SUB;j++) printf("%3d  ",score[STU][j]);
	puts("");
	
	return 0;
} 
