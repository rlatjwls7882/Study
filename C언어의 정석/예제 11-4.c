#include<stdio.h>
#include<string.h>

int main(void){
	char* fname="���� 11-4.c";
	char keyword[50]; //�˻��� �ܾ �Է¹޾� ������ �迭 
	char buf[1024]; //�� ���� ��� ���� �� �ִ� ����� ũ�⸦ �����Ѵ�
	int lineNo, result=0;
	
	FILE* fp=fopen(fname,"r");
	
	if(fp==NULL){
		printf("����[%s]�� �� �� �����ϴ�.\n",fname);
		exit(1);
	}
	
	printf("�˻��� �ܾ �Է��ϼ���.>");
	scanf("%s",keyword);
	
	for(lineNo=1;fgets(buf,sizeof(buf),fp);lineNo++){
		if(strstr(buf,keyword)){
			result++;
			printf("%3d: %s",lineNo,buf); //buf�� ���๮�ڰ� ���ԵǾ� ���� 
		}
	}
	
		printf("\n[%s]�� %d���� �࿡�� '%s'�� ã�ҽ��ϴ�.\n",fname,result,keyword);
		
		fclose(fp);
		return 0;
}
