#include<stdio.h>
#include<string.h> //strlen()�� ����ϱ� ���� �߰�

#define MAX_NUM 10

int main(){
	char word[MAX_NUM+1] ={0}; //�� ���ڸ� ������ ������ ���� 1�� ���Ѵ�
	int i, wordLen;
	char tmp; 
	
	printf("%d���������� �ܾ �Է��ϼ���.>",MAX_NUM);
	scanf("%s",word);
	
	printf("�Է��� �ܾ�:%s\n",word);
	wordLen = strlen(word); //char �迭 word�� ����� ���ڿ��� ���̸� ���Ѵ�.
	
	//���ڿ� ������ ����(wordLen/2) ��ŭ �ݺ��Ѵ�.
	
	for(i=0;i<wordLen/2;i++){
		tmp = word[i];
		word[i] = word[wordLen-1-i];
		word[wordLen-1-i] = tmp;
	} 
	
	printf("������ �ܾ�:%s\n",word);
	
	return 0;
}
