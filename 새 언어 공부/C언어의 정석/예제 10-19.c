#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* strReplace(char* src, char* old, char* new); 

int main(void){
	char* src="aabbccbbaa";
	
	printf("src=%s\n",src);
	printf("result=%s\n",strReplace(src,"bb","111"));
	printf("result=%s\n",strReplace(src,"cc",""));
	printf("result=%s\n",strReplace(src,"ff","00"));
	
	return 0;
}

char* strReplace(char* src, char* old, char* new){
	char* dst=(char*)calloc(strlen(src)*2,sizeof(char));
	char* sp=src; //�˻��� ������ ��ġ 
	char* dp=dst; //dst�� ������ ��ġ
	char* pos=NULL; //old�� �߰ߵ� ���� �ּҸ� ������ ����
	
	if(src==NULL||old==NULL||new==NULL) return src;
	
	while(pos=strstr(sp,old)){
		strncpy(dp,sp,pos-sp); //��ġ�� ��ġ ���������� ������ dst�� ����
		strcat(dp,new); //ġȯ�� ����(new)�� dst�� ����
		sp=pos+strlen(old); //sp�� �̵�
		dp+=strlen(dp); //dp�� �̵� 
	}
	
	strcat(dp,sp); //������ ������ dst�� �����Ѵ�
	
	return dst; 
}
