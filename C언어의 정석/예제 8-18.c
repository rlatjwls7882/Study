#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

char* toUpperCase(char* str){
	int len;
	len=strlen(str);
	
	char* ptr=(char*)malloc(sizeof(str));
	
	while(*str){
		if('a'<=*str&&*str<='z')
			*ptr++=(*str++)+('A'-'a');
		else
			*ptr++=*str++;
	}
	
	return ptr-len;
}

int main(void){
	printf("%s -> %s\n","abc",toUpperCase("abc"));
	printf("%s -> %s\n","a1b2c3",toUpperCase("a1b2c3"));
	
	return 0;
}
