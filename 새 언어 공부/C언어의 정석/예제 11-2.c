#include<stdio.h>

int main(void){
	char* fname1="C:\\Users\\rlatj\\Desktop\\C����� ����\\aaa.txt";
	char* fname2="C:\\Users\\rlatj\\Desktop\\C����� ����\\bbb.txt";
	
	FILE* in_f=fopen(fname1,"r");
	FILE* out_f=fopen(fname2,"w");
	int ch=0;
	
	if(!in_f||!out_f){ //if(!in_f==NULL||!out_f==NULL)
		printf("����[%s]�� �� �� �����ϴ�.\n",!in_f?fname1:fname2);
		return 1;
	}
	
	printf("[%s]�� [%s]�� ���縦 �����մϴ�.\n",fname1,fname2);
	
	while((ch=fgetc(in_f))!=EOF)
		fputc(ch,out_f);
		
	if(ferror(in_f)||ferror(out_f))
		printf("���� ���� �� ������ �߻��߽��ϴ�.\n");
	else
		printf("���� ���簡 �������ϴ�.\n");
	
	fclose(in_f);
	fclose(out_f);
	return 0;
}
