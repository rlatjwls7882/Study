#include<stdio.h>
#include<stdlib.h>

int main(void){
	char* fname="C:\\Users\\rlatj\\Desktop\\C����� ����\\test.txt";
	FILE* fwt=fopen(fname,"wt"); //�ؽ�Ʈ ���� ����
	FILE* frt=fopen(fname,"rt"); //�ؽ�Ʈ ���� �б�
	FILE* frb=fopen(fname,"rb"); //���� ���� �б�
	
	char buf[5];
	char* p=buf;
	int ch, cnt, i;
	
	fputc('a',fwt);
	fputc('b',fwt); 
	fputc('c',fwt);
	fputc('\n',fwt);
	fclose(fwt);
	
	printf("= �ؽ�Ʈ ���� �б� =\n");
	while((ch=fgetc(frt))!=EOF)
		printf("ch=%d\n",ch);
	
	printf("= ���� ���� �б� =\n");
	cnt=fread(buf, sizeof(char),10,frb);
	
	while((ch=fgetc(frt))!=EOF)
		printf("ch=%d\n",ch);
		
	for(i=0;i<cnt;i++)
		printf("ch=%d\n",buf[i]);
		
	fclose(frt);
	fclose(frb);
	
	return 0;
		
}
