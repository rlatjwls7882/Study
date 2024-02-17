#include<stdio.h>

int main(void){
	char* strArr[]={"abc","123","ABC","111",NULL};
	char* *p=strArr;
	int i;
	
	while(*p){
		printf("*p=%s, %p\n",*p,*p);
		p++;
	}
	
	p=strArr; //포인터의 값이 초기화되었으므로 다시 초기화
	
	//한 문자씩 출력
	while(*p){
		char *tmp=*p;
		while(*tmp){
			printf("%c",*tmp);
			tmp++;
		}
		p++;
	} 
	puts("");
	
	//strArr의 모든 문자열을 출력
	for(i=0;strArr[i];i++)
		printf("strArr[%d]=%s, %p\n",i,strArr[i],strArr[i]);
		
	return 0; 
}
