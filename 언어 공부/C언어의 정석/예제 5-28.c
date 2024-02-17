#include<stdio.h>

int main(){
	//��(BAN), ��(BUN), ����(SUB)
	int score[][4][3]={
		{//1��
			{100,100,100}, //1�� 1�� 
			{90,90,90}, //1�� 2�� 
			{80,80,80}, //1�� 3�� 
			{70,70,70} //1�� 4�� 
		},
		{//2�� 
			{95,95,90}, //2�� 1�� 
			{85,85,80}, //2�� 2�� 
			{75,75,70}, //2�� 3�� 
			{65,65,60} //2�� 4�� 
		}
	};
	
	int i,j,k;
	
	const int BAN = sizeof(score) / sizeof(score[0]);
	const int BUN = sizeof(score[0]) / sizeof(score[0][0]);
	const int SUB = sizeof(score[0][0]) / sizeof(score[0][0][0]);
	
	for(int i=0;i<BAN;i++){
		printf("[%d]��\n",i+1);
		for(int j=0;j<BUN;j++){
			printf("%d�� ",j+1);
			for(int k=0;k<SUB;k++) printf("%3d ",score[i][j][k]);
			puts("");
		}
		puts("");
	}
	
	for(i=0;i<BAN;i++) for(j=0;j<BUN;j++) for(k=0;k<SUB;k++) printf("score[%d][%d][%d]=%d\n",i,j,k,score[i][j][k]);
	
	return 0; 
}
