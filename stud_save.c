#include"student.h"

void save(sll *ptr)
{
	if(ptr==0)
	{
		printf("**** NO RECORS ARE PRESENT ****\n");
			return;
	}
	sll *t=ptr;
	FILE *f=fopen("student.data","w");
		while(t)
		{
			fprintf(f,"%d %s %f\n",t->roll,t->name,t->marks);
			t=t->nxt;
		}
		fclose(f);
		printf(" FILE SAVED SUCCESSFULLY \n");
}
