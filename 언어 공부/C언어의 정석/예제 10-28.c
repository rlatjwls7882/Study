#include<stdio.h>

#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
#define mid(x,y,z) ((x>y&&x>z) ? max(y,z) : (y>z&&y>x) ? max(x,z) : max(x,y))

int main(void){
	printf("mid(1,2,3)=%d\n",mid(1,2,3));
	printf("mid(1,1,1)=%d\n",mid(1,1,1));
	printf("mid(1,2,2)=%d\n",mid(1,2,2));
	printf("mid(1,1,2)=%d\n",mid(1,1,2));
	printf("mid(3,2,1)=%d\n",mid(3,2,1));
	printf("mid(2,1,3)=%d\n",mid(2,1,3));
	printf("mid(2,3,1)=%d\n",mid(2,3,1));
	
	return 0;
}
