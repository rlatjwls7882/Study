#include<stdio.h>

char* myStrchr(const char str[],char ch){
	for(;*str;str++) //*str�� �ι���('\0')�� �ƴ� ���� �ݺ�
		if(*str==ch) return str; //*str�� ch�� ������, str�� ��ȯ
		
	return NULL; //��ã���� NULL�� ��ȯ 
} 
int main(void){
	char* str="abcde";
	char* ptr=NULL;
	char ch;
	
	printf("str=%s, \t %p\n",str,str);
	
	ch='c';
	ptr = myStrchr(str,ch); //���ڿ� str���� ���� ch�� ã�´�
	
	if(ptr!=NULL)
		printf("ch=%c, \t\t %p\n",*ptr,ptr);
	else
		printf("\"%s\"���� '%c'�� ã�� �� �����ϴ�.\n",str,ch);
		
	ch='z';
	if((ptr=myStrchr(str,ch))) //if((ptr=myStrchr(str,ch))!=NULL)
		printf("ch=%c, \t\t %p\n",*ptr,ptr);
	else
		printf("\"%s\"���� '%c'�� ã�� �� �����ϴ�.\n",str,ch);
		
	return 0;
} 
