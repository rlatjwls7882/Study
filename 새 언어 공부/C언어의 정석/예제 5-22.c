#include<stdio.h>
#define LEN 5

int main(){
	char str[LEN]; //�Է¹��� ���ڿ��� ������ �迭
	char result[LEN]; //����� ������ �迭
	
	int i;
	int pos=0; // �迭 result�� ������ ��ġ
	
	printf("%d�� ������ ������ �Է��ϼ���.>",LEN-1);
	scanf("%s",str);
	
	for(i=0;str[i];i++) //���ڰ� ���� �Ǵ� ','�� ��츸 �迭 result�� �����Ѵ�.
	if(('0'<=str[i]&&str[i]<='9')||str[i]==',') result[pos++]=str[i];
	
	result[pos]='\0'; //�������� �� ���ڸ� �ִ� ���� ���� ����
	
	printf("str=%s\n",str);
	printf("result=%s\n",result);
	
	return 0; 
}
