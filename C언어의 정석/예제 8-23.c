#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void add(char* str);
void printArr(void); 

char** strArr; //���ڿ��迭(char*[])�� ������
int len=2; //���ڿ� �迭�� ���� 
int pos=0; //���ڿ��� ������ ��ġ(index)


int main(void){
	char input[50]; //����ڰ� �Է��� �ܾ �ӽ÷� ������ �迭
	int i;
	
	strArr=(char**)malloc(sizeof(char*)*len); //���ڿ��� ������ �迭�� �Ҵ����
	
	printf("������ �ܾ �Է��ϼ���.(ENTER:����)\n");
	printf(">");
	
	while(strlen(gets(input))){
		add(input);
		printf(">");
	} 
	//�迭�� �� ��Ұ� ����Ű�� �޸𸮸� ���� ����
	for(i=0;i<pos;i++){
		free(strArr[i]);
	} 
	
	free(strArr); //�迭�� �޸𸮸� ���� 
	
	return 0;
}  

void add(char* str){
	char* tmp=(char*)malloc(sizeof(char*)*(strlen(str)+1)); //�ι��ڸ� ������ ����
	
	if(pos>=len){
		//���� �迭���� �ι� ū �迭�� ���Ҵ����
		strArr = (char**)realloc(strArr,sizeof(char*)*len*2);
		len*=2; //���̸� �ι��. 
	} 
	
	strcpy(tmp, str);
	strArr[pos++]=tmp;
	
	printArr();
}

void printArr(void){
	int i;
	
	printf("strArr=%p [",strArr);
	
	for(i=0;i<pos;i++)
		printf("%s, ",strArr[i]);
		
	printf("] len=%d\n",len);
} 
