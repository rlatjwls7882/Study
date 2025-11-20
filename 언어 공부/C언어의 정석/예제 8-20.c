#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void add(char* str);
void printArr(void);

char** strArr; //문자열배열(char*[])의 포인터
int len=2;
int pos=0;

int main(void){
	char input[50]; //사용자가 입력한 단어를 임시로 저장할 배열
	
	strArr=(char**)malloc(sizeof(char*)*len); //문자열을 저장할 배열을 할당받음
	
	printf("저장할 단어를 입력하세요.(ENTER:종료)\n");
	printf(">");
	
	while(strlen(gets(input))){
		add(input);
		printf(">");
	} 
	
	return 0;
} 

void add(char* str){
	char* tmp=(char*)malloc(sizeof(char*)*(strlen(str)+1)); //널문자를 저장할 공간
	char** newStrArr;
	
	if(pos>=len){
		//기존 배열보다 두배 큰 배열을 새로 할당받음
		newStrArr = (char**)malloc(sizeof(char*)*len*2);
		
		//기존배열(strArr)의 내용을 새로운 배열(newStrArr)에 복사
		memcpy(newStrArr, strArr,sizeof(char*)*len);
		strArr=newStrArr; //새로운 배열의 주소를 strArr에 저장
		len*=2; 
	} 
	strcpy(tmp, str);
	strArr[pos++]=tmp;
	
	printArr();
}

void printArr(void){
	int i;
	
	printf("strArr=%p [",strArr);
	
	for(i=0;i<pos;i++)
		printf("%s, ",strArr[i]);
		
	printf("] len=%d\n",len);
}
