#include<stdio.h>
#define LEN 51
int main(){
	char str[LEN];
	int i, diff;
	
	printf("%d�� ������ �����ڸ� �Է��ϼ���.>",LEN-1);
	scanf("%s",str);
	
	printf("input=%s\n",str);
	diff = 'a' - 'A'; //�빮�ڿ� �ҹ����� �ڵ尪�� ���̸� ���Ѵ�.
	
	for(i=0;str[i];i++){ //for(i=0;str[i]!='\0';i++) {
		if('A'<=str[i] && str[i]<='Z') str[i] +=diff;
		else if('a'<=str[i] && str[i]<='z') str[i] -=diff;
	} 
	
	printf("result=%s\n",str);
	
	return 0;
} 
