#include<stdio.h>
#include<string.h> //strlen()을 사용하기 위해 추가
int main(){
	char str[]="Hello";
	char chArr[]={'H','e','l','l','o'};
	int i;
	int LEN = sizeof(str)/ sizeof(str[0]); //배열 str의 길이
	 
	printf("str=%s\n", str); //문자열은 지시자 %s로 츨력한다
	printf("chArr=%s\n",chArr);
	for(i=0;str[i]!='\0';i++); //str의 첫번쨰 요소부터, 널문자를 만날떄까지 i의 값을 증가
	
	printf("LEN=%d\n",LEN);
	printf("i=%d\n",i);
	printf("strlen(str)=%d\n",strlen(str));
	
	return 0; 
} 
