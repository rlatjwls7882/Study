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
	char* fname="C:\\Users\\rlatj\\Desktop\\C언어의 정석\\scoredata.txt";
	Student s;
	int i;
	
	char* inFormat="%d %s %d %d %d"; //지시자 사이의 공백 개수는 의미 없음. 
	char* outFormat="%2d %-10s %3d %3d %3d %4d %8.2f\n";
	
	if((fp=fopen(fname,"w"))==NULL){
		printf("파일[%s]을 열 수 없습니다.\n",fname);
		exit(1);
	} 
	printf("성적 데이터를 학번 이름 국어 수학 영어 순으로 입력하세요(종료:Enter)\n");
	
	while(1){
		printf(">");
		
		i=fscanf(stdin,inFormat,&s.no,&s.name,&s.kor,&s.math,&s.eng);
		if(i<5) break; //읽어들인 값의 개수가 부족하거나 EOF면 반복 종료
		
		fprintf(fp,inFormat,s.no,s.name,s.kor,s.math,s.eng);
	}
	fclose(fp);
	
	if((fp=fopen(fname,"r"))==NULL){
		printf("파일[%s]을 열 수 없습니다.\n",fname);
		exit(1);
	} 
	
	printf("no name       kor math eng total average\n");
	printf("================================================\n");
	
	while(1){
		i=fscanf(fp,inFormat,&s.no,&s.name,&s.kor,&s.math,&s.eng);
		if(i<5) break; //읽어들인 값의 개수가 부족하거나 EOF면 반복 종료
		
		s.totalScore=s.kor+s.eng+s.math;
		s.average=s.totalScore/3.0f;
		
		fprintf(stdout,outFormat,s.no,s.name,s.kor,s.math,s.eng,s.totalScore,s.average); 
	}
	
	fclose(fp);
	
	return 0;
}
