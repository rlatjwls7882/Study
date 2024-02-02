#include<stdio.h>

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
	FILE* fp;
	char* fname="C:\\Users\\rlatj\\Desktop\\C����� ����\\scoredata.txt";
	Student s;
	int i;
	
	char* inFormat="%d %s %d %d %d"; //������ ������ ���� ������ �ǹ� ����. 
	char* outFormat="%2d %-10s %3d %3d %3d %4d %8.2f\n";
	
	if((fp=fopen(fname,"w"))==NULL){
		printf("����[%s]�� �� �� �����ϴ�.\n",fname);
		exit(1);
	} 
	printf("���� �����͸� �й� �̸� ���� ���� ���� ������ �Է��ϼ���(����:Enter)\n");
	
	while(1){
		printf(">");
		
		i=fscanf(stdin,inFormat,&s.no,&s.name,&s.kor,&s.math,&s.eng);
		if(i<5) break; //�о���� ���� ������ �����ϰų� EOF�� �ݺ� ����
		
		fprintf(fp,inFormat,s.no,s.name,s.kor,s.math,s.eng);
	}
	fclose(fp);
	
	if((fp=fopen(fname,"r"))==NULL){
		printf("����[%s]�� �� �� �����ϴ�.\n",fname);
		exit(1);
	} 
	
	printf("no name       kor math eng total average\n");
	printf("================================================\n");
	
	while(1){
		i=fscanf(fp,inFormat,&s.no,&s.name,&s.kor,&s.math,&s.eng);
		if(i<5) break; //�о���� ���� ������ �����ϰų� EOF�� �ݺ� ����
		
		s.totalScore=s.kor+s.eng+s.math;
		s.average=s.totalScore/3.0f;
		
		fprintf(stdout,outFormat,s.no,s.name,s.kor,s.math,s.eng,s.totalScore,s.average); 
	}
	
	fclose(fp);
	
	return 0;
}
