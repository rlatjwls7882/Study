#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
	int input;
	int answer;
	
	srand((unsigned)time(NULL));
	answer = rand()%100+1; //1~100 ������ ������ ���� ����
	
	do{
		printf("1�� 100 ������ ������ �Է��ϼ���.>");
		scanf("%d",&input);
		
		if(input>answer) printf("�� ���� ���� �ٽ� �õ��غ�����.\n");
		else if(answer>input) printf("�� ū ���� �ٽ� �õ��غ�����.\n"); 
	} while(input!=answer);
	
	printf("�����Դϴ�.\n");
	
	return 0;
}
