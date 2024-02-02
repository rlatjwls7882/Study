#include<stdio.h>
#define BUF_SZ 4096

int main(void){
	char* filename1="C:\\Users\\rlatj\\Desktop\\C언어의 정석\\original.bin";
	char* filename2="C:\\Users\\rlatj\\Desktop\\C언어의 정석\\copy.bin";
	
	FILE* frb=fopen(filename1,"rb");
	FILE* fwb=fopen(filename2,"wb");
	
	char buf[BUF_SZ];
	int readSZ=BUF_SZ;
	
	if(frb==NULL){
		printf("파일 [%s]을 열 수 없습니다.\n",filename1);
		exit(1);
	}
	
	while(readSZ==BUF_SZ){
		readSZ=fread(buf,sizeof(char),BUF_SZ,frb);
		fwrite(buf,sizeof(char),readSZ,fwb);
	}
	
	if(feof(frb)) //feof() 파일이 끝인지 확인 
		printf("파일 [%s]을 [%s]로 복사에 성공했습니다.\n",filename1,filename2);
	else
		printf("파일 [%s] 복사에 실패했습니다.\n",filename1);
		
	fclose(frb);
	fclose(fwb);
	
	return 0;
}
