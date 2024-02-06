#include<stdio.h>

int main(){
	int score; //점수를 저장하기 위한 변수
	char grade = ' '; //학점을 저장하기 위한 변수. 공백으로 초기화한다.
	
	printf("점수를 입력하세요.>");
	scanf("%d",&score);
	
	if(score >= 90) grade='A'; // score가 90점보다 같거나 크면 A학점 
	else if(score >= 80) grade='B'; // score가 80점보다 같거나 크면 B학점
	else if(score >= 70) grade='C'; // score가 70점보다 같거나 크면 D학점
	else grade='D'; // 나머지는 D학점
	
	printf("당신의 학점은 %c입니다.",grade);
	
	return 0; 
}
