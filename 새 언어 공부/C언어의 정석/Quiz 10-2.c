#include<stdio.h>
#include<conio.h>
#include<ctype.h>

int main(void){
	char input[3]={0}; //�Է��� ������ �迭
	int pos=0;
	int ch;
	
	printf("3���� ���ڸ� �Է��ϼ���.>");
	
	while(1){
		ch=getch();
		
		if(ch=='\r'&&pos==3){ //'\r'=13, ���͸� �Է��ϸ� 13�� ����� 
			puts(""); //new line
			break;
		}
		
		if('1'<=ch && ch<='9'&&pos!=3){
			putch(ch);
			input[pos++]=ch;
		} else if(ch=='\b'&&pos!=0){ //backspace�� �������� 
			//������ ���ڸ� �����. backspace, ����, backspace�� �������� ��� 
			putch('\b'); //'\b'==8 ��ĭ ������ ���ư� 
			putch(' '); //���� ���ڰ� �ִ� ������ �������� ä�� 
			putch('\b'); //�ٽ� ��ĭ ������ ���ư� 
			input[--pos]='\0'; //������ ���ڸ� �ι��ڷ� ���� 
		}
	}
	
	printf("input:%s\n",input);
	return 0;
}
