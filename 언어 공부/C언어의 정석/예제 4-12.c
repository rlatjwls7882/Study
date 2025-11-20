#include<stdio.h>

int main(){
	char gender;
	char regNo[15]; // 문자열을 저장할 공간은 문자열의 길이보다 1이 커야 한다.
	
	printf("당신의 주민번호를 입력하세요.(011231-1111222)>");
	scanf("%s",regNo); //주민번호를 입력받는다.
	
	gender = regNo[7]; //입력받은 주민등록번호의 8번째 문자를 얻는다 
	
	switch(gender){
		case '1':
		case '3':
			switch(gender){
				case '1':
					printf("당신은 2000년 이전에 출생한 남자입니다.\n");
					break;
				case '3':
					printf("당신은 2000년 이후에 출생한 남자입니다.\n");
			} 
			break; //이 break문을 빼먹지 않도록 주의 
		case '2':
		case '4':
			switch(gender){
				case '2':
					printf("당신은 2000년 이전에 출생한 여자입니다.\n");
					break;
				case '4':
					printf("당신은 2000년 이후에 출생한 여자입니다.\n");
					break;
			} 
			break;
		default:
			printf("유효하지 않은 주민등록번호입니다.\n");
	} 
	
	return 0;
}
