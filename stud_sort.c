#include"student.h"

void sort_list(sll *ptr)
{
	if(ptr==0)
	{
		printf("**** NO RECORDS ARE PRESENT ****\n");
	return;
	}
sll *p1=malloc(sizeof(sll));
sll *p2=malloc(sizeof(sll));
sll t;
char op;
int i,j,c=count(ptr);
printf(" ENTER THE OPTION \n");
printf("N/n : Sort with name\n");
printf("P/p : Sort with marks\n");
scanf(" %c",&op);
if(op>='A'&&op<='Z')
op+=32;
switch(op)
{
case 'n':
	p1=ptr;
	for(i=0;i<c;i++)
	{
		p2=p1->nxt;
		for(j=0;j<c-1-i;j++)
		{
			if(strcmp(p1->name,p2->name)>0)
			{
				printf("%d\n",c);
				t.roll=p1->roll;
				strcpy(t.name,p1->name);
				t.marks=p1->marks;

				p1->roll=p2->roll;
				strcpy(p1->name,p2->name);
				p1->marks=p2->marks;

				p2->roll=t.roll;
				strcpy(p2->name,t.name);
				p2->marks=t.marks;
			}
			p2=p2->nxt;
		}
		p1=p1->nxt;
	}
	break;
case 'p':
	p1=ptr;
	for(i=0;i<c;i++)
	{
		p2=p1->nxt;
		for(j=0;j<c-1-i;j++)
		{
			if(p1->marks>p2->marks)
			{
				t.roll=p1->roll;
				strcpy(t.name,p1->name);
				t.marks=p1->marks;

				p1->roll=p2->roll;
				strcpy(p1->name,p2->name);
				p1->marks=p2->marks;

				p2->roll=t.roll;
				strcpy(p2->name,t.name);
				p2->marks=t.marks;
			}
			p2=p2->nxt;
		}
		p1=p1->nxt;
	}
	break;
default:
	printf(" **** ENTER THE CORRCT OPTION *****\n");
}
}
