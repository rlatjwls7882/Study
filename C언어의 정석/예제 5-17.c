#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_NUM 10
int main(){
	char word[MAX_NUM+1]; //�ι��ڸ� ������ ������ ���� 1�� ���Ѵ�
	int i, n, len=0;
	char tmp;
	
	srand((unsigned)time(NULL));
	
	printf("%d���������� �ܾ �Է��ϼ���.>",MAX_NUM);
	scanf("%s",word);
	
	printf("�Է��� �ܾ�:%s\n",word);
	 
	//�Է��� ������ ���� ����
	while(word[len]) len++; //while(word[len]!='\0') len++
	
	//�迭�� ����� ���ڵ��� ���� �ٲ۴�. (�ι��� ����)
	for(i=0;i<len*2;i++){
		n= rand()%len;
		
		tmp = word[0];
		word[0]=word[n];
		word[n]=tmp;
	} 
	printf("�ڼ��� �ܾ�:%s\n",word);
	
	return 0;
} 
