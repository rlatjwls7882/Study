#include<stdio.h>

int main(void){
	int arr[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
	int *p1=(int*)arr; //Ÿ���� �ٸ��Ƿ� ����ȯ�� �ʿ��ϴ�.
	int len = sizeof(arr)/sizeof(arr[0][0]);
	int sum=0;
	
	while(len--){
		printf("arr=%p\t*p1=%d\n",p1,*p1);
		sum += *p1++;	
	}
	 
	printf("sum=%d\n",sum);
	
	return 0;
}
