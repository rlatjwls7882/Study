#include<stdio.h>
int main(){
	int score[] = {79, 88, 91, 33, 100, 55, 95};
	
	int max = score[0]; //�迭�� ù��° ������ �ִ밪�� �ʱ�ȭ�Ѵ�. 
	int min = score[0]; //�迭�� ù��° ������ �ּҰ��� �ʱ�ȭ�Ѵ�. 
	
	const int LEN = sizeof(score)/sizeof(score[0]);
	int i;
	
	//�迭�� �ι�° ����� �б� ���ؼ� ���� i�� ���� 1�� �ʱ�ȭ�Ѵ�.
	for(i=1;i<LEN;i++){
		if(score[i]>max) max=score[i];
		else if(score[i]<min) min=score[i];
	} 

	printf("�ִ밪 : %d\n",max);
	printf("�ּҰ� : %d\n",min);
} 
