#include<stdio.h>

#define ROW 4
#define COL 3

int main(){
	int score[ROW][COL] = {
	{ 100, 100, 100},
	{ 20, 20, 20},
	{ 30, 30, 30},
	{ 40, 40, 40}
	};
	
	int i,j,sum=0;
	
	//�迭�� ��� ��Ҹ� ���̺� ���·� ����Ѵ�
	
	for(i=0;i<ROW;i++){
		for(j=0;j<COL;j++){
		printf("%3d ",score[i][j]);
		sum +=score[i][j]; //�� ����� ���� sum�� �����Ѵ�. 
		}
	printf("\n");
	}
	printf("sum=%d\n\n",sum);
	
	//�迭�� ��� ��Ҹ� ���ٿ� �ϳ��� ������� ����Ѵ�.
	for(i=0;i<ROW;i++) for(j=0;j<COL;j++) printf("score[%d][%d]=%d\n",i,j,score[i][j]);
	
	return 0;
} 
