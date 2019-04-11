#include<stdio.h>
#include<stdlib.h>
#include"list.h"

int main()
{ 


	banji class1;
	student stu1 = (student)malloc(sizeof(struct students));
	student stu2;
    char end;
	stu1->name = "Mike";
	stu1->age = 19;
	stu1->next = NULL;

	InitList(&class1);
    append(&class1,stu1);
	appendinf(&class1,"Tom",21);
	appendinf(&class1,"John",19);
	insertinf(&class1,"Mary",18,2);

    showAll(&class1);
	overturn(&class1);
    showAll(&class1);	
	
	   
    end=getchar();
          
}