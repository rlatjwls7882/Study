#include<stdio.h>
#pragma warning(disable:4996) // 대체 함수를 사용하라는 경고를 없앨 떄 사용 
int main(){
	float f;
	double d;
	
	printf("두 개의 실수를 입력해주세요>");
	scanf("%f%lf", &f, &d); //두 지시자 사이의 공백은 있어도 되고 없어도 된다.
	
	printf("입력하신 실수는 %f입니다.\n", f);
	printf("입력하신 실수는 %f입니다.\n", d);
	
	return 0; 
}
