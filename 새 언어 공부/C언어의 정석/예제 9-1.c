#include<stdio.h>

typedef struct student{
	int no;
	char name[10];
	int kor, math, eng;
} Student;

int main(void){
	Student s1; //struct student s1;�� ����
	Student s2={2,"JOHN",100,90,80};
	
	s1=s2;
	
	s1.no=1;
	s1.name[0]='S'; //name�� ù��° ���ڸ� 'S'�� ����
	
	printf("s1.no=%d\n",s1.no);
	printf("s1.name=%s\n",s1.name);
	printf("s1.kor=%d\n",s1.kor); 
	printf("s1.math=%d\n",s1.math); 
	printf("s1.eng=%d\n",s1.eng); 
	puts("");
	printf("s2.no=%d\n",s2.no);
	printf("s2.name=%s\n",s2.name);
	printf("s2.kor=%d\n",s2.kor); 
	printf("s2.math=%d\n",s2.math); 
	printf("s2.eng=%d\n",s2.eng); 
	
	return 0;
}

