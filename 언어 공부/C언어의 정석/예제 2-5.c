#include<stdio.h>
int main(){
	short s= 0x1234567890; // 10������ �� 780�� 
	int i=0x1234567890; // int�� �ִ밪�� �� 20�� 
	printf("%#llx=%lld\n\n", 0x1234590,0x1234567890);
	
	//16������ ���
	printf("[16����]\n");
	printf("s=%#x\n",s); //%x�� ������ 16������ ���·� ����Ѵ�. 
	printf("i=%#x\n",i); //#�� 16���� �տ� ���λ� 0x�� �ٿ��ش�. 
	printf("\n");
	
	//10������ ���
	printf("[10����]\n");
	printf("s=%d\n",s);
	printf("i=%d\n",i);
	printf("\n"); 
} 
