#include<stdio.h>
#include<stdlib.h>
#include"list.h"

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

//单向链表反转
//递归写法：反转剩下len-1的链表，把当前节点加到最后去
//当剩一个时，直接返回
void overturn(banji *B)
{
	student p;
	if(B->len==1) return;
	p = pop(B,1);
	overturn(B);
	append(B,p);
}