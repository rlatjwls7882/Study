#include<stdio.h>
int main(){
	int C,num,sum=0,std=0;
	float average;
	int score[1000];
	scanf("%d",&C); //테스트 케이스 수 
	
	while(C--){
		scanf("%d",&num); //학생 수 
		
		for(int i=0;i<num;i++){
			scanf("%d",&score[i]);
			sum+=score[i];
		}
		
		average = sum / (float)num;
		
		for(int i=0;i<num;i++) if(score[i]>average) std++;
		
		printf("%.3f%%\n",(std/(float)num)*100);
		
		sum=0,std=0; //초기화 
	}
}