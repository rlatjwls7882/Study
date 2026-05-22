#include<stdio.h>

void swapStr(char** ps1,char** ps2){
	char* tmp = *ps1;
	*ps1=*ps2;
	*ps2=tmp;
}

int main(void){
	char* str1 = "ABC";
	char* str2 = "123";
	
	printf("str1=%s, str2=%s\n",str1,str2);
	
	swapStr(&str1,&str2);
	
	printf("str1=%s, str2=%s\n",str1,str2);
	
	return 0;
}
