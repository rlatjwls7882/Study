#include<stdio.h>

int main(void){
	char* fname1="C:\\Users\\rlatj\\Desktop\\C언어의 정석\\aaa.txt";
	char* fname2="C:\\Users\\rlatj\\Desktop\\C언어의 정석\\bbb.txt";
	char buf[1024];
	
	FILE* in_f = fopen(fname1,"r");
	FILE* out_f=fopen(fname2,"w");
	
	if(!in_f||!out_f){
		printf("파일[%s]를 열 수 없습니다.\n",!in_f?fname1:fname2);
		exit(1);
	}
	
	printf("[%s]를 [%s]로 복사를 시작합니다.\n",fname1,fname2);
	
	while(fgets(buf,sizeof(buf),in_f)!=NULL)
		fputs(buf,out_f);
	
	if(ferror(in_f)||ferror(out_f))
		printf("파일 복사 중 에러가 발생했습니다.\n");
	else
		printf("파일 복사가 끝났습니다.\n");
	
	fclose(in_f);
	fclose(out_f);
	
	return 0;
}
