#include<stdio.h>
#include<stdlib.h>

int main(void){
	unsigned char buf[16]; //unsigned char Ÿ���� �迭 
	int i, cnt;
	
	char* fname="C:\\Users\\rlatj\\Desktop\\C����� ����\\score.dat";
	FILE* in_f=fopen(fname,"rb");
	
	if(!in_f){
		printf("����[%s]�� �� �� �����ϴ�.\n",fname);
		exit(1);
	}
	
	while((cnt=fread(buf,1,sizeof(buf),in_f))>0){
		for(i=0;i<cnt;i++)
			printf("%02X ",buf[i]); 
		printf("\n");
	} 
	fclose(in_f);
	
	return 0;
}
