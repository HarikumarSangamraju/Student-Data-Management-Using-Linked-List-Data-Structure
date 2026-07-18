#include"student.h"

void add_new(sll **ptr)
{
	sll *new=malloc(sizeof(sll));
	printf("     Enter the student data       \n");
	printf("---------------------------------\n");
	scanf("%s%f",new->name,&new->marks);
	if(*ptr==0)
	{
		*ptr=new;
		new->roll=1;
		new->nxt=0;
	}
	else{
		sll *t=*ptr;
		if((*ptr)->roll!=1)
		{
			new->roll=1;
			new->nxt=*ptr;
			*ptr=new;
			return;
		}
		while((t->nxt)&&((t->roll+1)==(t->nxt->roll)) )
			t=t->nxt;
		if(t->nxt==0)
		{
			t->nxt=new;
			new->roll=t->roll+1;
			new->nxt=0;
			return;
		}
		new->roll=t->roll+1;
		new->nxt=t->nxt;
		t->nxt=new;

	}
}
