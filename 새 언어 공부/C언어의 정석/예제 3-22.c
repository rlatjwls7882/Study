#include<stdio.h>
int main(){
	char ch;
	
	printf("���ڸ� �ϳ� �Է��ϼ���.>");
	scanf("%c",&ch);
	
	if('0'<=ch && ch <= '9') printf("�Է��Ͻ� ���ڴ� �����Դϴ�.\n");
	if(('a'<=ch && ch<= 'z') || ('A'<= ch && ch<='Z')) printf("�Է��Ͻ� ���ڴ� �������Դϴ�.\n");
	
	return 0;
}
