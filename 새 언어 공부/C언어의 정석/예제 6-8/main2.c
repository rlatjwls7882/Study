#include<stdio.h>
#include "header.h"

int main(void){
	int dan = getUserInput(); //int getUserInput(void)�� ȣ��
	
	if(2<=dan&&dan<=9) printGugudan(dan); //void printGugudan(dan)�� ȣ�� 
	else printGugudanAll(); //void printGugudanAll(void)�� ȣ�� 
	
	return 0; 
}
