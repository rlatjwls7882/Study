#include<stdio.h>

#define DEBUG
#define print_int(x) printf(#x"=%d\n",x)

#if 1 //1�� 0���� �ٲٸ� #if ~ #else ������ �ּ�ó�� �ȴ�.
int main(void){
	int x=10;
	
#ifdef DEBUG //#if defined(DEBUG)
	print_int(x);
#endif
	
	return 0;
} 
#else
int main(void){
	printf("Hello, world.\n");
	return 0;
}
#endif
