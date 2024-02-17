#include<stdio.h>
int main(){
	int score[] = {79, 88, 91, 33, 100, 55, 95};
	
	int max = score[0]; //배열의 첫번째 값으로 최대값을 초기화한다. 
	int min = score[0]; //배열의 첫번째 값으로 최소값을 초기화한다. 
	
	const int LEN = sizeof(score)/sizeof(score[0]);
	int i;
	
	//배열의 두번째 요솝터 읽기 위해서 변수 i의 값을 1로 초기화한다.
	for(i=1;i<LEN;i++){
		if(score[i]>max) max=score[i];
		else if(score[i]<min) min=score[i];
	} 

	printf("최대값 : %d\n",max);
	printf("최소값 : %d\n",min);
} 
