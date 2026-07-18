#include"student.h"

void load_list(sll **ptr)
{
	FILE *f=fopen("student.data","r");
	if(f==0)
		return;   /* no saved data yet, start with an empty list */

	sll *tail=0;
	int r;
	char n[20];
	float m;

	while(fscanf(f,"%d %s %f",&r,n,&m)==3)
	{
		sll *new=malloc(sizeof(sll));
		new->roll=r;
		strcpy(new->name,n);
		new->marks=m;
		new->nxt=0;

		if(*ptr==0)
		{
			*ptr=new;
			tail=new;
		}
		else
		{
			tail->nxt=new;
			tail=new;
		}
	}
	fclose(f);
}
