#include<stdio.h>
#include<string.h> //strcpy()�� ����ϱ� ���� �߰� 
int main(){
	 char strArr[][4] = {"abc","def","ghi"};
	 char tmp[4];
	 int i,j;
	 
	 const int ROW = sizeof(strArr) / sizeof(strArr[0]);
	 
	for(i=0;i<ROW;i++) printf("strArr[%d]=%s\n",i,strArr[i]);
	puts("");
	
	//�迭 tmp�� �̿��ؼ�, ù��° ��(strArr[0])�� �ι�°��(strArr[1])�� �ٲ۴�.
	strcpy(tmp, strArr[0]);
	strcpy(strArr[0],strArr[1]);
	strcpy(strArr[1],tmp);
	
	//�� ��° ���� ������ �� ���ھ� �����Ѵ�.
	strArr[2][0] = 'G';
	strArr[2][1] = 'G';
	strArr[2][2] = '\0';
	
	for(i=0;i<ROW;i++) printf("strArr[%d]=%s\n",i,strArr[i]);
	
	return 0; 
	
} 
