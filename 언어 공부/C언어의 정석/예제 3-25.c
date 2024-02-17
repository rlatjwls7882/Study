#include<stdio.h>
#define LEN 32

//int Ÿ���� ������ 2������ ����ϴ� �Լ�
void printToBinary(int dec){
	char bin[LEN] = {0};
	int pos = LEN;
	int i;
	
	do {
		bin[--pos] = (dec&1);
		dec = dec >> 1;
		dec = dec &0x7fffffff;
	} while(dec!=0);
	
	for(i=0;i<LEN;i++) printf("%d", bin[i]);
	printf("\n");
} 

int main(){
	unsigned x = 0xAB;
	unsigned y = 0xF;
	
	printf("x = %#X \t\t\t",x); printToBinary(x);
	printf("y = %#X \t\t\t",y); printToBinary(y);
	
	printf("%#X | %#X = %#X \t\t",x,y,x|y); printToBinary(x|y);
	printf("%#X & %#X = %#X \t\t",x,y,x&y); printToBinary(x&y);
	printf("%#X ^ %#X = %#X \t\t",x,y,x^y); printToBinary(x^y);
	printf("%#X ^ %#X ^ %#X = %#X \t\t",x,y,x^y^y); printToBinary(x^y^y);
	
	return 0;
	
}
