#include<stdio.h>
int main(){
	char strArr2D[][3][7]={//3차원 char 배열(2차원 문자열 배열) 
		{"[0][0]", "[0][1]", "[0][2]"},
		{"[1][0]", "[1][1]", "[1][2]"},
		{"[2][0]", "[2][1]", "[2][2]"}
	};
	int i,j;
	
	const int ROW = sizeof(strArr2D) / sizeof(strArr2D[0]); 
	const int COL = sizeof(strArr2D[0]) / sizeof(strArr2D[0][0]);
	
	for(int i=0;i<ROW;i++) for(int j=0;j<COL;j++) printf("strArr[%d] [%d]=%s\n",i,j,strArr2D[i][j]);
	
	return 0; 
}
