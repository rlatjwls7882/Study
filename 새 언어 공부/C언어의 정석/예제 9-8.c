#include<stdio.h>
#include<stdlib.h>
 
typedef struct student{
	int no;
	char name[10];
	int kor, math, eng;
	int total;
	float average;
} Student;

Student inputStuInfo(void);
Student* inputStuInfo2(void);
void printStudent(Student s);
void printStudent2(Student *p);

int main(void){
	Student stu=inputStuInfo();
	Student* p=inputStuInfo2();
	
	printStudent(stu); //���� ���� ȣ��
	printStudent2(p); //������ ���� ȣ��
	
	return 0; 
}

Student inputStuInfo(){
	Student s;
	
	printf("�л� ������ �Է��ϼ���.(��ȣ, �̸�, ����, ����, ����)>");
	scanf("%d%s%d%d%d",&s.no,s.name,&s.kor,&s.math,&s.eng);
	
	return s;
}

Student* inputStuInfo2(){
	Student *p=malloc(sizeof(Student)); //����ü ������ ���� �Ҵ�
	
	printf("�л� ������ �Է��ϼ���.(��ȣ, �̸�, ����, ����, ����)>");
	scanf("%d%s%d%d%d",&p->no,p->name,&p->kor,&p->math,&p->eng);
	
	return p;
}

void printStudent(Student s){
	s.total=s.kor+s.math+s.eng;
	s.average=s.total/3.0f;
	
	printf("%2d %10s %3d %3d %3d %3d %6.2f\n",s.no,s.name,s.kor,s.eng,s.eng,s.total,s.average);
}

void printStudent2(Student *p){
	p->total=p->kor+p->math+p->eng;
	p->average=p->total/3.0f;
	
	printf("%2d %10s %3d %3d %3d %3d %6.2f\n",p->no,p->name,p->kor,p->eng,p->eng,p->total,p->average);
}
