#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
	int i=atoi(" 123 ");
	double d1=atof("-3.14");
	double d2=atof("1.23e3");
	
	char buffer[10];
	char* str="abcd";
	char* ptr; //��ȯ�� ��ģ �ּҸ� �����ϱ� ���� ������
	long l=strtol(str,&ptr,16); //���ڿ� str�� 16������ �����ؼ� ��ȯ
	
	if(ptr!=str+strlen(str))
		printf("��ȯ�� ������ �߻��߽��ϴ�.\n");
	else
		printf("l=%#X\n",l); //0xABCD
	
	printf("i=%d\n",i);
	printf("d1=%f\n",d1);
	printf("d2=%f\n",d2); 
	
	sprintf(buffer, "%X",i); //i�� 16���� ���ڿ��� ��ȯ�ؼ� buffer�� ����
	printf("i=%s\n",buffer);
	
	sscanf(buffer,"%X",&i); // buffer�� 16���� ���ڿ��� ��ȯ�ؼ� i�� ����
	printf("i=%d\n",i);
	
	return 0; 
}
