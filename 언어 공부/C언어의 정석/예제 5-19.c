#include<stdio.h>
int main(){
	const char hex[]="0123456789ABCDEF";
	int num;
	printf("������ �Է��ϼ���.>");
	scanf("%d",&num);
	while(num){ //while(num!=0){
		printf("%10d...%2d %c\n",num/16,num%16,hex[num%16]);
		num/=16; //num�� 16���� ���� ����� num�� �ٽ� �����Ѵ�. 
	}
	
	return 0;
}
