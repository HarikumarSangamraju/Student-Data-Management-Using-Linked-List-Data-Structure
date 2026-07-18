#include"student.h"

void delete_all(sll **ptr)
{
	if(ptr==0)
	{
		printf("**** NO RECORS ARE PRESENT ****\n");
			return;
	}
	sll *del=malloc(sizeof(sll));
	del=*ptr;
	while(del)
	{
		*ptr=del->nxt;
		free(del);
		del=*ptr;
	}
printf("----- RECORDS DELETED SUCCESSFULLY ------\n");
}
