#include<stdio.h>
#include<math.h>
int main(){
	int menu;
	int num;
	
	while(1){
		printf("(1) square\n");
		printf("(2) square root\n");
		printf("(3) log\n");
		printf("���ϴ� �޴�(1~3)�� �����ϼ���. (����:0)>");
		scanf("%d", &menu);
		
		if(menu==0){ //if(!menu){
			printf("���α׷��� �����մϴ�.\n");
			break;
		}
		else if(!(1<=menu && menu<=3)){
			printf("�޴��� �߸� �����ϼ̽��ϴ�.(����� 0)\n");
			continue; 
		}
		
		printf("�����Ͻ� �޴��� %d�Դϴ�.\n", menu);
	}
	
	return 0;
} 

