#include<stdio.h>
#include<string.h>

int main(void){
	char chArr[]="abc";
	char *ps="abc";
	int i;
	
	printf("chArr=%s, ps=%s\n",chArr,ps);
	
	for(i=0;i<sizeof(chArr);i++) 
		printf("chArr[%d]=%c, ps[%d]=%c\n",i,chArr[i],i,ps[i]);
	
	strcpy(chArr,"ABC"); //OK. ���ڹ迭 chArr�� ���ڿ� ����� ������ ����
//	strcpy(ps,"ABC"); //����. ���ڿ� ����� ������ ������ �� ����.
//	chArr="ABC"; //����. ���(�迭�̸� chArr)�� ������ �� ����.
	ps="ABC"; //OK. ���ڿ� ����� �ּҸ� ps�� ����
	chArr[1]='Z'; //OK. ���ڹ迭 chArr�� �ι�° ��Ҹ� ����
//	ps[1]='Z'; //����. ���ڿ� ����� ������ ������ �� ����. 

	printf("chArr=%s, ps=%s\n",chArr,ps);
	
	return 0;
}
