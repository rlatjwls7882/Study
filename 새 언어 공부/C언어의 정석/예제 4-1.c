#include<stdio.h>

int main(){
	int x = 0;
	
	printf("x=%d �϶�, ���� ����\n",x);
	
	if(x==0) printf("x==0\n");
	if(x!=0) printf("x!=0\n");
	if(x) printf("x\n");
	if(!x) printf("!x\n");
	
	x=1;
	printf("\nx=%d �϶�, ���� ����\n",x);
	
	if(x==0) printf("x==0\n");
	if(x!=0) printf("x!=0\n");
	if(x) printf("x\n");
	if(!x) printf("!x\n");
	
	return 0;
} 
