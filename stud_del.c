#include"student.h"

void delete_a_node(sll **ptr)
{
	if(*ptr==0)
	{
		printf("**** NO RECORDS ARE PRESENT ****\n");
	return;
	}
sll *del=malloc(sizeof(sll));
sll *prev=malloc(sizeof(sll));
char op;
int d=0;
char n[20];
printf("                                   \n");
printf("    **** ENTER THE OPTION ****   \n");
printf("----------------------------------\n");
printf("| R/r : Enter rollno to delete   |\n");
printf("| N/n : Enter name to delete     |\n");
printf("----------------------------------\n");
scanf(" %c",&op);
if(op>='A'&&op<='Z')
op+=32;
switch(op){
case 'r':
	del=*ptr;
	printf(" ENTER THE ROLL NUMBER TO DELETE \n");
	scanf("%d",&d);
	prev=*ptr;
	while(del)
	{
		if(del->roll==d)
		{
			if(del==*ptr)
			{
				*ptr=del->nxt;
				free(del);
				printf("----- DELETED SUCCESSFULLY ------\n");
				return;
			}
			else
			{
				prev->nxt=del->nxt;
				free(del);
				printf("----- DELETED SUCCESSFULLY ------\n");
				return;
			}
		}
		prev=del;
		del=del->nxt;
	}
case 'n':
	del=*ptr;
	printf(" ENTER THE NAME TO DELETE \n");
	scanf("%s",n);
	prev=*ptr;
	while(del)
	{
		if(strcmp(del->name,n)==0)
		{
			if (del==*ptr)
			{
				*ptr=del->nxt;
				free(del);
				printf("----- DELETED SUCCESSFULLY ------\n");
				return;	
			}
			else
			{
				prev->nxt=del->nxt;
				free(del);
				printf("----- DELETED SUCCESSFULLY ------\n");
				return;
			}
		}
		prev=del;
		del=del->nxt;
	}
default:
	printf(" **** ENTER THE CORRCT OPTION *****\n");
}
}
