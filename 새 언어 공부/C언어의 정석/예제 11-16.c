#include<stdio.h>
#include<stdlib.h>

typedef struct student{
	int no;
	char name[10];
	int kor;
	int math;
	int eng;
	int totalScore;
	float average;
} Student;

int main(void){
	Student stuArr[]={
		{1,"KIM",100,100,100},
		{2,"LEE",90,90,90},
		{3,"CHOI",70,75,70},
		{4,"PARK",80,80,80}
	};
	const int SIZE=sizeof(stuArr)/sizeof(Student);
	Student s;
	int i;
	
	char* fname="C:\\Users\\rlatj\\Desktop\\C����� ����\\score2.dat";
	FILE* fp=fopen(fname,"wb+"); //�������(�����)�� ������ open
	
	if(!fp){
		printf("����[%s]�� �� �� �����ϴ�.\n",fname);
		exit(1);
	} 
	
	//����ü �迭�� ���Ͽ� ���
	fwrite(stuArr,sizeof(Student),SIZE,fp);
	fflush(fp);
	
	printf("pos=%d\n",ftell(fp));
	
	//rewind()�� ������ �� ó������ �̵�. �׷��� ������ ���� �� ����.
	rewind(fp); //fseek(fp, 0, SEEK_SET);�� ����
	
	printf("pose=%d\n",ftell(fp));
	
	//���Ϸκ��� ����ü�� �ϳ��� �о ȭ�鿡 ���
	printf("= ������� ��� =\n");
	for(i=0;i<SIZE;i++){
		fread(&s,sizeof(Student),1,fp); //����ü�� �ϳ� �д´�
		printf("%d %-8s %3d %3d %3d pos=%d\n",s.no,s.name,s.kor,s.math,s.eng,ftell(fp)); 
	} 
	
	//������ ���������� ����ü�� �ϳ��� �������� �о ȭ�鿡 ���
	printf("\n= �������� ��� =\n");
	for(i=1;i<=SIZE;i++){
		fseek(fp,sizeof(Student)*-i,SEEK_END);
		fread(&s,sizeof(Student),1,fp); //����ü�� �ϳ��� �д´�.
		printf("%d %-8s %3d %3d %3d\n",s.no,s.name,s.kor,s.math,s.eng); 
	} 
	
	fclose(fp);
	
	return 0;
}
