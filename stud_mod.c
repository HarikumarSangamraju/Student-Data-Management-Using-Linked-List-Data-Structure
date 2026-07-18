#include"student.h"

void modify(sll **ptr)
{
	if(ptr==0)
	{
		printf("**** NO RECORDS ARE PRESENT ****\n");
	return;
	}
sll *new=malloc(sizeof(sll));
char op;
int r=0,c=0;
char n[20];
float f;
printf("                                   \n");
printf("    **** ENTER THE OPTION ****   \n");
printf("----------------------------------\n");
printf("| R/r : TO search a ROLLNO       |\n");
printf("| N/n : TO search a NAME         |\n");
printf("| P/p : based on PERCENTAGE      |\n");
printf("----------------------------------\n");
scanf(" %c",&op);
if(op>='A'&&op<='Z')
op+=32;
switch(op){
case 'r':
	new=*ptr;
	printf("ENTER THE ROLLNO\n");
	scanf("%d",&r);
	while(new)
	{
		if(new->roll==r)
		{
			printf("ENTER DATA TO MODIFY\n");
			scanf("%s%f",new->name,&new->marks);
			return;
		}
		new=new->nxt;
	}
	printf("**** THE ROLLNO IS NOT PRESENT ****\n");
case 'n':
	new=*ptr;
	printf("ENTER THE NAME\n");
	scanf("%s",n);
	while(new)
	{
		if(strcmp(new->name,n)==0)
			{
			printf("%d %s %f\n",new->roll,new->name,new->marks);
			c++; }
			new=new->nxt;
	}
	if(c>0)
	{
	printf(" **** ENTER ROLLNO TO MODIFY ****\n" );
	scanf("%d",&r);
	new=*ptr;
	while(new)
	{
		if(new->roll==r)
		{
			printf("ENTER DATA TO MODIFY\n");
			scanf("%s%f",new->name,&new->marks);
			return;
		}
		new=new->nxt;
	}
	}
	else
		printf("**** NO RECORDS ARE PRESENT ****\n");
case 'p':
	new=*ptr;
	printf("ENTER THE MARKS\n");
	scanf("%f",&f);
	while(new)
	{
		if(new->marks==f)
		{
			printf("%d %s %f\n",new->roll,new->name,new->marks);
			c++;
		}
		new=new->nxt;
	}
	if(c>0)
	{
	printf(" **** ENTER ROLLNO TO MODIFY ****\n" );
	scanf("%d",&r);
	new=*ptr;
	while(new)
	{
		if(new->roll==r)
		{
			printf("ENTER DATA TO MODIFY\n");
			scanf("%s%f",new->name,&new->marks);
			return;
		}
		new=new->nxt;
	}
	}
	else
		printf("**** NO RECORDS ARE PRESENT ****\n");
default:
	printf(" **** ENTER THE CORRCT OPTION *****\n");
}
}
