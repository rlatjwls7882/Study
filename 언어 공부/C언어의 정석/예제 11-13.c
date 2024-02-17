#include<stdio.h>
#define BUF_SZ 4096

int main(void){
	char* filename1="C:\\Users\\rlatj\\Desktop\\C����� ����\\original.bin";
	char* filename2="C:\\Users\\rlatj\\Desktop\\C����� ����\\copy.bin";
	
	FILE* frb=fopen(filename1,"rb");
	FILE* fwb=fopen(filename2,"wb");
	
	char buf[BUF_SZ];
	int readSZ=BUF_SZ;
	
	if(frb==NULL){
		printf("���� [%s]�� �� �� �����ϴ�.\n",filename1);
		exit(1);
	}
	
	while(readSZ==BUF_SZ){
		readSZ=fread(buf,sizeof(char),BUF_SZ,frb);
		fwrite(buf,sizeof(char),readSZ,fwb);
	}
	
	if(feof(frb)) //feof() ������ ������ Ȯ�� 
		printf("���� [%s]�� [%s]�� ���翡 �����߽��ϴ�.\n",filename1,filename2);
	else
		printf("���� [%s] ���翡 �����߽��ϴ�.\n",filename1);
		
	fclose(frb);
	fclose(fwb);
	
	return 0;
}
