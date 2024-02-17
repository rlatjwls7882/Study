#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define SIZE 5

int main(){
	int bingo[SIZE][SIZE];
	int i, j, x, y, tmp, num;
	
	//�迭�� ��� ��Ҹ� 1���� SIZE*SIZE������ ���ڷ� �ʱ�ȭ
	for(int i=0;i<SIZE*SIZE;i++) bingo[i/SIZE][i%SIZE]=i+1;
	
	//�迭�� ����� ���� �ڼ��´�.(shuffle)
	srand(time(NULL));
	
	for(i=0;i<SIZE*SIZE;i++){
		x=rand()%SIZE;
		y=rand()%SIZE;
		
		//1�� 1���� ��(bingo[0][0])�� ���Ƿ� ���õ� ��(bingo[x][y])�� �ٲ۴�.
		tmp = bingo[0][0];
		bingo[0][0] = bingo[x][y];
		bingo[x][y] = tmp; 
	} 
	
	do {
		for(i=0;i<SIZE;i++) {
			for(j=0;j<SIZE;j++) printf("%2d ",bingo[i][j]);
			puts("");	
		}
		puts("");
		
		printf("1~%d�� ���ڸ� �Է��ϼ���.(����:0)",SIZE*SIZE);
		scanf("%d",&num);
	
		for(i=0;i<SIZE*SIZE;i++){
			if(bingo[i/SIZE][i%SIZE]==num){
				bingo[i/SIZE][i%SIZE]=0;
				break;
			}
		}
	} while(num!=0);
	
	return 0;
} 
