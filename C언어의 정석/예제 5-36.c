#include<stdio.h>
#define STU 4 //학생 수
#define SUB 3 //과목 수

int main(){
	int score[][STU+1][SUB+1]={
		{ //1반 
			{100,100,100},
			{25,20,20},
			{35,30,30},
			{45,40,40}
		},
		{ //2반 
			{95,95,90},
			{85,85,80},
			{75,75,70},
			{65,65,60}
		}
	};
	const int BAN = sizeof(score)/ sizeof(score[0]);
	int i,j,k;
	
	for(i=0;i<BAN;i++) {
		printf("[%d반]\n",i+1);
		printf("번호 국어 영어 수학 총점 평균\n");
		printf("=========================================\n");
		
		
		for(j=0;j<STU;j++) {
			printf(" %d  ",j+1);
			
			for(k=0;k<SUB;k++){
				score[i][j][SUB]+=score[i][j][k];
				score[i][STU][k]+=score[i][j][k];
				
				
				printf("%3d  ",score[i][j][k]);
			}
			// 학생별 총점과 평균을 출력
			printf(" %4d  %5.1f\n",score[i][j][SUB],score[i][j][SUB]/(float)SUB); 
			
		}
		
		printf("=========================================\n");
		printf("총점 ");
		
		for(k=0;k<SUB;k++) printf("%3d  ",score[i][STU][k]);
		
		printf("\n\n");
	}
	
	return 0;
} 

