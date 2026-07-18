#include"student.h"

void reverse_list(sll **ptr)
{
	if(*ptr==0)
	{
		printf("**** NO RECORDS ARE PRESENT ****\n");
		return;
	}
	int c=count(*ptr);
	if(c>1)
	{
		sll **a=malloc(sizeof(sll*)*c);
		sll *t=*ptr;
		int i=0;
		while(t)
		{
			a[i++]=t;
			t=t->nxt;
		}
		for(i=c-1;i>0;i--)
			a[i]->nxt=a[i-1];
		a[0]->nxt=0;
		*ptr=a[c-1];
	}
}
