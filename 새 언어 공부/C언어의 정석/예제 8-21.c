#include<stdio.h>
#include<stdlib.h>

#define MB (1024*1024)

int main(void){
	int mem=1024; //�Ҵ� ��û�� �޸�
	int total=0; //�Ҵ� ��û�� ������ �޸��� ����
	
	while(mem){ 
		if(malloc(mem*MB)){
			total+=mem;
			printf("total=%d, mem=%d\n",total,mem);
		}
		else
			mem/=2; //�Ҵ翡 �����ϸ� ��û�� �޸𸮸� ������ ���� 
	} 
	printf("total=%d MB\n",total);
	return 0;
}
