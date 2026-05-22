#include<stdio.h>
#include<errno.h> //errno와 에러코드가 정의되어있다.

int main(void){
	char* filename="C:\\Users\\rlatj\\Desktop\\C언어의 정석\\opentest.txt";
	FILE* fp=fopen(filename,"r");
	
	if(fp==NULL){
		printf("읽기모드로 파일 [%s] 열기에 실패했습니다.\n",filename);
		printf("errno=%d\n",errno); //발생한 에러코드를 출력한다. 
	} else{
		printf("읽기모드로 파일 [%s] 열기에 성공했습니다.\n",filename);
	}
	
	fp=fopen(filename,"w");
	errno=0; //에러코드를 초기화
	
	if(fp==NULL){
		printf("쓰기모드로 파일 [%s] 열기에 실패했습니다.\n",filename);
		printf("errno=%d\n",errno); //발생한 에러코드를 출력한다. 
	} else{
		printf("쓰기모드로 파일 [%s] 열기에 성공했습니다.\n",filename);
	}
	
	printf("FOPEN_MAX=%d\n",FOPEN_MAX);
	
	fclose(fp);
	printf("파일 [%s]를 닫습니다.\n",filename);
	
	
	return 0;
} 
