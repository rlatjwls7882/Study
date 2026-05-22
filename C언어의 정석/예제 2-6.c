#include<stdio.h>
#define EMAIL "ask@codechobo.com"
int main(){
	char ch=65; //char ch = 'A';
	char email[] = "ask@codechobo.com";

	int i =0xFF; //10진수로 255, 8진수로 377
	long long ll=12345678901234LL;

	unsigned ui = 0xFFFFffff; 
	unsigned long long ull=0xFFFFffffFFFFffffLL;
	
	printf("ch='%c', %d\n", ch, ch);
	printf("i=%d, %x, %X, %o, %O\n", i, i, i, i, i, i);
	printf("ll=%d\n",ll); //long long 타입을 출력할 떄는 %lld 사용
	 
	printf("ui=%u, %#x, %d\n",ui,ui,ui); // unsigned에는%d가 아닌 %u 사용 
	printf("ull=%llu, %#llx, %lld\n", ull, ull, ull);
	
	printf("\"Hello, world\"\n");
	printf("ask me, EMAIL please.\n");
	printf("ask me, " EMAIL " please.\n");
	printf("ask me, %s please.\n", email);
	
	printf("[12345678901234567890]\n");
	printf("[%s]\n", email);
	printf("[%20s]\n", email);
	printf("[%-20s]\n", email);
	printf("[%.8s]\n", email);
	
	return 0;
}
