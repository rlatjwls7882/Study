#include<stdio.h>
#define LEN 10
int main(){
	char str[LEN+1]; // �ִ� ���̰� 10�� ���ڿ��� ���尡��
	int i;
	
	printf("���̰� %d ������ ���ڿ��� �Է��ϼ���.>",LEN);
	gets(str);
	
	printf("str=");
	puts(str); //���ڿ��� ����ϰ� �ٹٲ��� �Ѵ�. 
	
	for(i=0;i<LEN+1;i++) printf("str[%d]=%c, %d\n",i,str[i], str[i]);
	
	return 0;	 
}
