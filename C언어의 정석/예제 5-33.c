#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define LEN 11
int main(){
	char words[][LEN] = {"television", "computer", "mouse", "phone"};
	char question[LEN];
	char answer[50];
	
	int i,j,n,word_len;
	char tmp;
	
	const int WORD_CNT = sizeof(words)/sizeof(words[0]);
	
	srand((unsigned)time(NULL));
	
	for(i=0;i<WORD_CNT;i++){
		word_len=strlen(words[i]);
		strcpy(question,words[i]); //�ܾ �迭 question�� ���� 
		
		for(j=0;j<word_len;j++){
			n=rand()%word_len;

			tmp=question[j];
			question[j]=question[n];
			question[n]=tmp;
		}
		printf("Q%d. %s�� ������ �Է��ϼ���.>",i+1,question);
		gets(answer);
		
		if(strcmp(words[i],answer)==0) printf("�¾ҽ��ϴ�.\n");
		else printf("Ʋ�Ƚ��ϴ�.\n");
	}
	
	return 0;
} 
