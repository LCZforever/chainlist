#ifndef LIST_H
#define LIST_H

typedef struct students{
	char *name;
	int age;
	struct students* next;
}*student,*pos;

typedef struct banji{
	student head,tail;
	int len;
}banji;

void showAll(banji* B);
void append(banji* B,student S);
void InitList(banji* B); 
void appendinf(banji* B,char* name,int age);
void insertinf(banji* B,char* name,int age,int pos);
student pop(banji* B,int pos);
void overturn(banji *B);


#endif