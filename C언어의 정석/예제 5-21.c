#include<stdio.h>
int main(){
	char word[20];
	int i, score, sum=0;
	
	printf("�ܾ �ϳ� �Է��ϼ���.(�ҹ��ڷθ�)>");
	scanf("%s",word);
	
	for(i=0;word[i];i++){ //for(i=0;word[i]!=0;i++) {
		score = word[i] - 'a'+1;
		printf("%c %d\n", word[i], score);
		sum += score;
	}
	
	printf("sum=%d\n",sum);
	
	return 0;
}
