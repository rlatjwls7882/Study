#include<stdio.h>

int main(){
	char op;
	int x,y;
	double result;
	
	printf("����� ���� �Է��Ͻÿ�.(�Է¿� 3+4)>");
	scanf("%d%c%d",&x,&op,&y);
	
	switch(op){
		case '+':
			result = x+y;
			break;
		case '-':
			result = x-y;
			break;
		case 'x':
		case '*':
			result = x*y;
			break;
		case '/':
			if(y!=0) result = x/(double)y;
			else result = 0;
			break;
		default:
			op='?';
	}
	if(op!='?'){
		if((int)result ==result) printf("%d %c %d = %d\n",x,op,y,(int)result);
		else printf("%d %c %d = %f\n",x,op,y,result);
	}
	else printf("�Է��Ͻ� �����ڴ� �������� �ʽ��ϴ�.\n");
	
	return 0;
}
