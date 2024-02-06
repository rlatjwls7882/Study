#include<stdio.h>
#define STU 4 //�л� ��
#define SUB 3 //���� ��

//�迭 score�� ���������� ���� 
	int score[STU+1][SUB+1]={
		{100,100,100},
		{25,20,20},
		{35,30,30},
		{45,40,40}
	};

void sumScore(void); //������ ����ϴ� �Լ�
void printScore(void); //������ ����ϴ� �Լ�

int main(){
	sumScore();
	printScore();
	return 0;
}

void sumScore(void){
	int i,j;
	for(i=0;i<STU;i++) {
		for(j=0;j<SUB;j++){
				score[i][SUB]+=score[i][j];
				score[STU][j]+=score[i][j];
		}
	}
}

void printScore(void){
	int i,j;
	printf("��ȣ ���� ���� ���� ���� ���\n");
	printf("=========================================\n");
	
	for(i=0;i<STU;i++) {
		printf(" %d  ",i+1);
		
		for(j=0;j<SUB;j++)
			printf("%3d  ",score[i][j]);
			
		printf(" %3d  %5.1f\n",score[i][SUB],score[i][SUB]/(float)SUB); 
	}
	printf("=========================================\n���� ");
	
	for(j=0;j<SUB;j++) printf("%3d  ",score[STU][j]);
	
	puts("");
}
