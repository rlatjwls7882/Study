#include<stdio.h>
#include<string.h>

char* strinsert(char* dst,char* src,int n){
	char tmp[10]={0};
	int i,j;
	
	for(i=n,j=0;i<strlen(src);i++,j++)
		tmp[j]=src[i];
	
	for(i=n,j=0;j<strlen(dst);i++,j++)
		src[i]=dst[j];
	
	for(i=n+strlen(dst),j=0;j<strlen(src)-n;i++,j++)
		src[i]=tmp[j];
		
	
	return src;
}

int main(void){
	char str[10]="abcd";
	
	printf("%s\n",strinsert("123",str,1));
	printf("%s\n",strinsert("123",str,2));
	printf("%s\n",strinsert("123",str,3));
	
	return 0;
}
