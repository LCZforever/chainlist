#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
typedef struct students{
	char *name;
	int age;
	struct students* next;
}*student,*pos;

typedef struct banji{
	student head,tail;
	int len;
}banji;

void InitList(banji* B)
{   
	student head,tail;
	head = (student)malloc(sizeof(student));
	tail = (student)malloc(sizeof(student));
	head->next = tail;
	tail->next = NULL;
	B->head = head;
	B->tail = tail;
	B->len = 0;
}
 
void append(banji* B,student S)
{
	student p = B->head;
	while(p->next!=B->tail){p=p->next;}
	p->next=S;
	S->next=B->tail;
	B->len++;
}

void appendinf(banji* B,char* name,int age)
{  
	student stu = (student)malloc(sizeof(struct students));
	student p = B->head;
    while(p->next!=B->tail){p=p->next;}
	stu->name = name;
	stu->age = age;
    p->next = stu;
	stu->next = B->tail;  
    B->len++;
}

void insertinf(banji* B,char* name,int age,int pos)
{
	int i=1;
	student stu = (student)malloc(sizeof(struct students));
	student p=B->head;
	if(pos>B->len || pos<1)
  	{
		printf("Pos is worng");
		return;
	}	
	stu->name = name;                       
	stu->age = age;
	
	while(i<pos)
	 {
		p=p->next;
		i++;
	}

	stu->next = p->next;
	p->next = stu;
	B->len++;
}

student pop(banji* B,int pos)
{
	student p = B->head;
	student q;
	int i=1;
	if(pos>B->len || pos<1)
  	{
		printf("Pos is worng");
		return NULL;
	}	
	while(i<pos)
	{
		i++;
		p = p->next;
	}
	q = p->next;
	p->next = q->next;
	B->len--;
	return q;
}	

void showAll(banji* B)
{ 
	student p = B->head->next;
	if(p==B->tail)
	{
		printf("The list is null");
		return;
 	}
	while(p!=B->tail)
	{
		printf("Name : %s Age : %d\n",p->name,p->age);
		p=p->next;
	}
	printf("Lenth is : %d\n",B->len);
}

	
int main()
{ 
	void showAll(banji* B);
	void append(banji* B,student S);
    void InitList(banji* B); 
	void appendinf(banji* B,char* name,int age);
	void insertinf(banji* B,char* name,int age,int pos);
    student pop(banji* B,int pos);

	banji class1;
	student stu1 = (student)malloc(sizeof(struct students));
	student stu2;
	stu1->name = "Mike";
	stu1->age = 19;
	stu1->next = NULL;

	InitList(&class1);
    append(&class1,stu1);
	appendinf(&class1,"Tom",21);
	appendinf(&class1,"John",19);
	insertinf(&class1,"Mary",18,2);
    stu2 = pop(&class1,3);

    showAll(&class1);	
	printf("%s\n",stu2->name);
	system("pause");
	return 0;
}
