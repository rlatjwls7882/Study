#include<stdio.h>
#include<errno.h> //errno�� �����ڵ尡 ���ǵǾ��ִ�.

int main(void){
	char* filename="C:\\Users\\rlatj\\Desktop\\C����� ����\\opentest.txt";
	FILE* fp=fopen(filename,"r");
	
	if(fp==NULL){
		printf("�б���� ���� [%s] ���⿡ �����߽��ϴ�.\n",filename);
		printf("errno=%d\n",errno); //�߻��� �����ڵ带 ����Ѵ�. 
	} else{
		printf("�б���� ���� [%s] ���⿡ �����߽��ϴ�.\n",filename);
	}
	
	fp=fopen(filename,"w");
	errno=0; //�����ڵ带 �ʱ�ȭ
	
	if(fp==NULL){
		printf("������� ���� [%s] ���⿡ �����߽��ϴ�.\n",filename);
		printf("errno=%d\n",errno); //�߻��� �����ڵ带 ����Ѵ�. 
	} else{
		printf("������� ���� [%s] ���⿡ �����߽��ϴ�.\n",filename);
	}
	
	printf("FOPEN_MAX=%d\n",FOPEN_MAX);
	
	fclose(fp);
	printf("���� [%s]�� �ݽ��ϴ�.\n",filename);
	
	
	return 0;
} 
