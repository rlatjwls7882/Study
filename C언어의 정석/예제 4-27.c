#include<stdio.h>
int main(){
	int num;
	int sum = 0;
	int flag=1; //while���� ���ǽĿ� ���� ���� 
	
	printf("�հ踦 ���� ���ڸ� �Է��ϼ���.(�������� 0�� �Է�)\n");
	while(flag){ //flag���� 1�̹Ƿ� ���ǽ��� ���� �ȴ�. 
		printf(">>");
		scanf("%d",&num); //���ڸ� �Է¹޴´�.
		
		if(num!=0) sum+=num; //num�� 0�� �ƴϸ�, sum�� ���Ѵ� 
		else flag=0;  //num�� 0�̸�, flag�� ���� 0���� ����, ���ǽ��� ������ �ȴ�. 
	}
	printf("�հ�:%d\n",sum);
	
	return 0;
}
