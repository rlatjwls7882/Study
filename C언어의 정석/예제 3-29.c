#include<stdio.h>
int main(){
	int x,y,z;
	int absX,absY,absZ;
	char signX,signY,signZ;
	
	x = 10;
	y = -5;
	z = 0;
	
	absX = x>=0 ? x:-x; //x�� ���� �����̸� ����� �����.
	absY = y>=0 ? y:-y;
	absZ = z>=0 ? z:-z;
	
	signX = x>0 ? '+':(x==0?' ':'-'); //���� �����ڸ� ��ø
	signY = y>0 ? '+':(y==0?' ':'-');
	signZ = z>0 ? '+':(z==0?' ':'-');
	
	printf("x=%c%d\n",signX,absX);
	printf("y=%c%d\n",signY,absY);
	printf("z=%c%d\n",signZ,absZ); 
	
	return 0;
}
