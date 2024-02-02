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
int multiply(int x,int y){
	int result=x*y;
	return result;
}
int getUserInput(void){
	int num;
	
	printf("input a number(2~9) :");
	
	scanf("%d",&num);
	return num;
}
void printGugudan(int dan){
	int i;
	for(i=1;i<=9;i++){
		int result = multiply(dan,i); //int multiply(int x,int y)�� ȣ�� 
		printf("%d*%d=%2d\n",dan,i,result);
	}
}
void printGugudanAll(void){
	int i,j;
	for(i=1;i<=9;i++){
		for(j=2;j<=9;j++) printf("%d*%d=%2d ",j,i,multiply(j,i));
		printf("\n");
	}
}
