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
		
		for(;;){
			printf("����� ���� �Է��ϼ���.(��� ����:0, ��ü ����:-1)>");
			scanf("%d", &num);
			
			if(num==0) break; //�������. for���� �����.
			if(num==-1) goto exit; //��ü����. for���� while���� ��� �����. 
			
			switch(menu){
				case 1: printf("result=%d\n", num*num); break;
				case 2: printf("result=%lf\n", sqrt((double)num)); break;
				case 3: printf("result=%lf\n", log((double)num)); break;
			}
		} //for(;;)
	}
	
	exit:
	return 0;
} 
