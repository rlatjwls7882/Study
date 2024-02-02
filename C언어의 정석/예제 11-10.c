#include<stdio.h>

int main(void){
	char* filename1="C:\\Users\\rlatj\\Desktop\\C����� ����\\data.bin";
	char* filename2="C:\\Users\\rlatj\\Desktop\\C����� ����\\data.txt";
	
	FILE* fwb=fopen(filename1,"wb");
	FILE* fwt=fopen(filename2,"wt");
	FILE* frb=fopen(filename1,"rb");
	FILE* frt=fopen(filename2,"rt");
	
	char* str="AB12";
	int i=12;
	float f=12.625f;
	int ch;
	
	//data.bin�� ���� 
	fwrite(str,sizeof(char),strlen(str),fwb);
	fwrite(&i,sizeof(int),1,fwb);
	fwrite(&f,sizeof(float),1,fwb);
	
	//data.txt�� ����
	fprintf(fwt,"%s%d%6.3f",str,i,f);
	
	fclose(fwb);
	fclose(fwt);
	
	//data.bin���� �б�
	printf("= %s = \n",filename1);
	while((ch=fgetc(frb))!=EOF) //fgetc()�� 1byte�� �о ���
		printf("%02X %c\n",ch,ch);
	printf("\n\n");
	
	//data.txt���� �б�
	printf("= %s = \n",filename2);
	while((ch=fgetc(frt))!=EOF)
		printf("%02X %c\n",ch,ch);
	printf("\n\n");
	
	fclose(frb);
	fclose(frt);
	return 0;
}
