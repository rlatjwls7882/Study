#include<stdio.h>

int main(void){
	char* filename="C:\\Users\\rlatj\\Desktop\\C����� ����\\ONE_HUNDRED_MB2.txt";
	FILE* fp=fopen(filename,"w");
	
	int fileSize=1024*1024*1024; //100MB
	
	fseek(fp,fileSize-1,SEEK_SET);
	
	if(fputc('\0',fp)==EOF){
		printf("���� ������ �����Ͽ����ϴ�.\n");
		exit(1);
	}
	
	fclose(fp);
	
	printf("%s�� �����Ǿ����ϴ�.\n",filename);
	
	fp=fopen(filename,"r"); //������ ������ �б� ���� �ٽ� ����
	
	fseek(fp,0,SEEK_END); //���� �����͸� ������ ������ �̵�
	printf("�� ������ ũ��� %ld bytes�Դϴ�.\n",ftell(fp));
	
	fclose(fp);
	
	return 0; 
}
