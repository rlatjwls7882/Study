#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(void){
	int i;
	double num;
	
	srand((unsigned)time(NULL)); //������ ���Ѱ�(seed)�� ���� �ð����� �ʱ�ȭ
	
	for(i=0;i<10;i++){
		num=(rand()/(double)RAND_MAX); //0.0<=num<=1.0
		printf("%f, ",num);
		
		num=(int)(num*100)/100.0;
		printf("%f\n",num);
	} 
	
	return 0;
}
