#include<stdio.h>

typedef struct student{
	int no;
	char name[8];
	int kor;
	int math;
	int eng;
}Student;

int main(void){
	Student stuArr[]={
		{1,"KIM",100,100,100},
		{2,"LEE",90,90,90},
		{3,"CHOI",80,80,80}
	};
	const int SIZE=sizeof(stuArr)/sizeof(Student);
	Student s;
	int i;
	
	char* fname="C:\\Users\\rlatj\\Desktop\\C����� ����\\score.dat";
	FILE* in_f=fopen(fname,"rb");
	FILE* out_f=fopen(fname,"wb");
	
	if(!in_f||!out_f){
		printf("����[%s]�� �� �� �����ϴ�.\n",fname);
		exit(1);
	}
	
	//����ü �迭 ��ü'sizeof(Student)*SIZE'�� ���Ͽ� ���
	fwrite(stuArr,sizeof(Student),SIZE,out_f);
	fflush(out_f); //���ۿ� �����ִ� ������ ��� ����ϰ� ���۸� ����.
	
	//���Ϸκ��� ����ü�� �ϳ��� �о ȭ�鿡 ���
	for(i=0;i<SIZE;i++){
		//����ü�� �ϳ�'sizeof(Student)*1'�� �д´�.
		fread(&s,sizeof(Student),1,in_f);
		printf("%d %-8s %3d %3d %3d\n",s.no,s.name,s.kor,s.math,s.eng); 
	} 
	fclose(in_f);
	fclose(out_f);
	return 0;
}
