#include"student.h"

void show_list(sll *ptr)
{
	if(ptr==0)
	{
		printf("**** NO RECORDS ARE PRESENT ****\n");
		return;
	}
	sll *t=ptr;
		printf("ROLLNO     NAME         MARKS\n");
	while(t)
	{
		printf("  %d : %s       %f\n",t->roll,t->name,t->marks);
		t=t->nxt;
	}
}
