#include<stdio.h>
#define print_int(x) printf(#x"=%d\n",x)
#define print_txt(txt) printf(#txt"\n")

int main(void){
	int x=5,y=7;
	
	print_int(x);
	print_int(y);
	print_int(x + y);
	print_int(x          +          y         -2);
	print_txt(
		���ϴ� ������
		�����Ӱ� \n
		\b��������. 
	);
	return 0;
}

