#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
	int numArr[10];
	const int LEN = sizeof(numArr) / sizeof(numArr[0]);
	int i, j, k, tmp;
	
	int chk; //�ڸ��ٲ��� �߻��ߴ��� Ȯ���ϴ� ����
	
	srand((unsigned)time(NULL));
	
	for(i=0;i<LEN;i++){
		numArr[i] = rand() %10;
		printf("%d",numArr[i]);
	} 
	printf("\n");
	
	for(i=0;i<LEN-1;i++) {
	chk=0; //�� �ݺ����� chk�� 0���� �ʱ�ȭ�Ѵ�.
	
	for(j=0;j<LEN-1-i;j++){
		if(numArr[j]>numArr[j+1]){ //���� ���� ������ ���� �ٲ۴� 
			tmp =numArr[j];
			numArr[j]=numArr[j+1];
			numArr[j+1]=tmp;
			
			chk = 1; //�ڸ��ٲ��� �߻������� chk�� 1�� �ٲ۴� 
		}
	} //end of for j
	
	if(chk==0) break; //�ڸ��ٲ��� ������ �ݺ����� �����. 
	
	for(k=0;k<LEN;k++) printf("%d",numArr[k]);
	printf("\n");
	} //end of for i
	
	return 0;
} 
