#include<stdio.h>

int main(){
	int score[] = {100, 88, 100, 100, 90};
	const int LEN = sizeof(score)/sizeof(score[0]);
	
	int i,sum=0; //������ �����ϱ� ���� ����
	float average = 0.0f; //����� �����ϱ� ���� ����
	
	for(i=0;i<LEN;i++){
		sum +=score[i]; // �迭�� �� ��Ҹ� ���� sum�� ���Ѵ�.
		printf("score[%d]=%d\tsum=%d\n",i,score[i],sum); 
	} 
	
	average=sum/(float)LEN; // ������� �Ҽ������� ��� ���� float�� ����ȯ 
	
	printf("���� : %d\n", sum);
	printf("��� : %4.1lf\n",average);
	
	return 0;
}
