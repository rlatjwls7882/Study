#include<stdio.h>

int main(){
	int i=200;
	int *ptr=&i;
	
	*ptr = *ptr + 1; // i = i + 1l과 같은 의미이다. 
	
	printf("i=%d\n",i);
	printf("*ptr=%d\n",*ptr);
	printf("&i=%p\n",&i);
	printf("ptr=%p\n",ptr); 
	
	return 0;
}
