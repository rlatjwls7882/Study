#include<stdio.h>

int main(void){
	int arr[]={1,2,3,4,5,6};
	int *ptr=&arr[0];
	
	const int LEN = sizeof(arr)/sizeof(arr[0]);
	
	int sum=0, avg=0;
	
	for(int i=0;i<LEN;i++){
		sum+=*ptr;
		avg+=*ptr++;
	}
	printf("sum=%d\navg=%.6f",sum,(float)avg/LEN);
	
	return 0;
}
