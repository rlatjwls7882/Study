#include<stdio.h>
int multiply(int x,int y);
int getUserInput(void);
void printGugudan(int dan);
void printGugudanAll(void);

int main(void){
	int dan = getUserInput(); //int getUserInput(void)�� ȣ��
	
	if(2<=dan&&dan<=9) printGugudan(dan); //void printGugudan(dan)�� ȣ�� 
	else printGugudanAll(); //void printGugudanAll(void)�� ȣ�� 
	
	return 0; 
}
