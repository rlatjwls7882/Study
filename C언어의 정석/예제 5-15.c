#include<stdio.h>
#define LEN 10
int main(){
	char str[LEN+1]; // �ִ� ���̰� 10�� ���ڿ��� ���尡��
	int i;
	
	printf("���̰� %d ������ ���ڿ��� �Է��ϼ���.>",LEN);
	scanf("%10s",str);
	
	printf("str=%s\n",str);
	
	for(i=0;i<LEN+1;i++) printf("str[%d]=%c, %d\n",i,str[i], str[i]);
	
	return 0;	 
}
