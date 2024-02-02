#include<stdio.h>

int main(){
	int score;
	char grade;
	char opt = '0';
	 
	printf("점수를 입력하세요.>");
	scanf("%d",&score);
	printf("당신의 점수는 %d입니다.\n",score);
	
	if(score >= 90){ // score가 90점보다 같거나 크면 A학점(grade) 
		grade='A';
		if(score >=98) opt='+'; //90점 이상 중에서도 98점 이상은 A+ 
		else if(score<94) opt='-'; //90점 이상 중에서도 94점 미만은 A- 
	} 
	else if(score >= 80){ // score가 80점보다 같거나 크면 B학점(grade) 
		grade='B';
		if(score >=88) opt='+'; //80점 이상 중에서도 88점 이상은 B+ 
		else if(score<84) opt='-'; //80점 이상 중에서도 84점 미만은 B- 
	} 
	else grade='C'; // 나머지는 C학점(grade) 
	
	printf("당신의 학점은 %c%c입니다.",grade,opt);
	
	return 0; 
}
