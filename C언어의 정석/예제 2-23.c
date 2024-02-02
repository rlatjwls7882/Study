#include<stdio.h> 
int main(){
	int i =91234567;
	float f=(float)i;
	int i2=(float)i;
	
	double d = (double)i;
	int i3 = (int)f;
	
	float f2 = 1.666;
	int i4 = (int)f2;
	
	printf("i=%d\n", i);
	printf("f=%f i2=%d\n",f,i2);
	printf("d=%f i3=%d\n",d,i3);
	printf("(int)%f=%d\n",f2,i4);
	return 0;
}
