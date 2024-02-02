#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

void shuffle(char* arr,int len){
	int i, idx;
	char tmp;
	
	for(i=0;i<len;i++){
		idx=rand()%len;
		tmp=arr[i];
		arr[i]=arr[idx];
		arr[idx]=tmp;
	}
}

char* makeQuestion(char* answer){//answer�� �ڼ�� ���� ���ڿ��� ��ȯ 
	const int LEN= strlen(answer);
	char* q=calloc(LEN+1,sizeof(char)); //�ι��ڰ� ����� ������ �ʿ�
	
	memcpy(q,answer,LEN); //answer�� q�� ����. strncpy(q, answer, LEN);
	shuffle(q,LEN); //q�� ���ڸ� �ڼ��´�. 
	
	return q; 
}

char* getHint(char* hint,char* answer, int len){ //��Ʈ�� ���� ��ȯ 
	int i,idx,cnt=0;
	char* tmp;
	
	for(i=0;i<len;i++) //answer�� ���Ե�'_'�� ������ ����.
		if(hint[i]=='_')
			cnt++;
		
	if(cnt<=2) return hint; //'_'�� ������ 2�� ���ϸ� hint�� �״�� ��ȯ
	
	while(1){
		idx=rand()%len;
		
		if(hint[idx]=='_'){ //������ ��ġ(idx)�� '_'�� ���乮�ڷ� ��ü
			hint[idx]=answer[idx];
			break; 
		}
	}
	
	return hint;
}

int main(void){
	char* strArr[]={"change","love","hope","view"};
	const int LEN=sizeof(strArr)/sizeof(strArr[0]);
	char *question, *answer;
	char input[50]; //����ڰ� �Է��� ������ ������ �迭
	char hint[50]; //��Ʈ�� ������ �迭
	
	srand((unsigned)time(NULL));
	
	answer=strArr[rand()%LEN]; //strArr���� ������ ���ڿ��� �� answer�� ����
	question=makeQuestion(answer); //answer�� �����ؼ� ������ ����� ��ȯ
	
	memset(hint, '_', strlen(answer)); //hint�� '_'�� ä���. 
	hint[strlen(answer)]='\0';
	
	while(1){
		printf("Question:%s\n",question);
		printf("Your answer is :");
		
		gets(input); //���� �Է¹޴´�.
		
		if(memcmp(answer,input,strlen(answer))==0){ //�Է��� ������ ����� �� 
			printf("Correct!!!\n");
			break;
		} else{ //������ �ƴϸ�, ��Ʈ�� �����ش�. 
			printf("Wrong answer, try again!!!\n");
			printf("Hint:%s\n\n",getHint(hint,answer,strlen(answer)));
		}
	}
	
	return 0;
}
