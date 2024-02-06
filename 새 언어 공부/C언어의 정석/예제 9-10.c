#include<stdio.h>
#include<stdlib.h>

typedef struct student{
	int no;
	char name[10];
	int kor, math, eng;
	int totalScore;
	float average;
} Student;

void inputData(Student* pArr[]);
void printStuArr(const Student* pArr[]);

int size=0; //��������. ������ �迭�� ����� �������� ����

int main(void){
	Student *pArr[100] ={NULL};
	
	inputData(pArr); //ȭ�����κ��� �����͸� �Է¹޾Ƽ� pArr�� ����
	printStuArr(pArr); //�����͸� ���
	
	return 0; 
} 

void inputData(Student* pArr[]){
	Student* p;
	int n;
	
	printf("�л� ������ �Է��ϼ���.(��ȣ, �̸�, ����, ����, ���� ������)\n");
	printf("�Է��� ��� ��ģ �Ŀ��� q�� �Է��ϰ� EnterŰ�� ��������.\n");
	
	while(1){
		p=malloc(sizeof(Student)); //����ü ������ �����Ҵ� ����
		
		printf(">");
		n=scanf("%d%s%d%d%d",&p->no,p->name,&p->kor,&p->math,&p->eng);
		
		if(n!=5){ //�о���� ���� ������ 5�� �ƴϸ� �ݺ� ���� 
			free(p);
			break;
		} 
		p->totalScore=p->kor+p->math+p->eng;
		p->average=p->totalScore/3.0f;
		
		pArr[size++]=p; //���� �Ҵ� ���� ����ü ������ �ּҸ� ������ �迭�� ���� 
	}
}

void printStudent(const Student* p){
	printf("%-4d %-10s %4d %4d %4d %4d %6.2f\n",p->no,p->name,p->kor,p->eng,p->eng,p->totalScore,p->average);
} 

void printStuArr(const Student* pArr[]){
	printf("\n��ȣ �̸�       ���� ���� ���� ���� ���\n");
	printf("======================================================\n");
	
	while(*pArr)
		printStudent(*pArr++);
}
