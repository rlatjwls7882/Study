#include<stdio.h>
int main(){
	int num;
	int sum=0;
	
	printf("���ڸ� �Է��ϼ���. (��:12345)>");
	scanf("%d",&num);
	
	while(num){ //while(num!=0)
		//num�� 10���� ���� �������� sum�� ����
		sum+=num%10;
		printf("sum=%3d num=%d\n",sum, num);
		
		num /=10; //num = num /10; num�� 10���� ���� ���� �ٽ� num�� ���� 
	}
	
	printf("�� �ڸ����� ��:%d\n", sum);
	return 0;
} 
