#include"student.h"

int main()
{
	char op;
	int cnt=0;
	sll *hptr=0;

	load_list(&hptr);   /* load any previously saved records from student.data */

	while(1)
	{
		printf("\033[51m________________________________\n");
		printf("| **** STUDENT RECORD MENU **** |\n");
		printf("|  --------------------------   |\n");
		printf("| a/A : Add new record          |\n");
		printf("| d/D : Deleat a node           |\n");
		printf("| s/S : Show the list           |\n");
		printf("| m/M : Modify a record         |\n");
		printf("| v/V : Save                    |\n");
		printf("| e/E : Exit                    |\n");
		printf("| t/T : Sort the list           |\n");
		printf("| b/B : Delate all the records  |\n");
		printf("| r/R : Reverse the list        |\n");
		printf("---------------------------------\033[0m\n");
		scanf(" %c",&op);
		if(op>='A'&&op<='Z')
			op+=32;
		switch(op){

			case 'a':add_new(&hptr);break;
			case 's':show_list(hptr);break;
			case 'e':exit_list(hptr);break;
			case 'v':save(hptr);break;
			case 'b':delete_all(&hptr);break;
			case 'm':modify(&hptr);break;
			case 'd':delete_a_node(&hptr);break;
			case 't':sort_list(hptr);break;
			case 'c':cnt=count(hptr);
				 printf("%d\n",cnt);break;
			case 'r':reverse_list(&hptr);break;
			default :printf(" **** ENTER CORRECT OPTIOIN ****\n");
		}
	}
}

void exit_list(sll *ptr)
{
	if(ptr==0)
	{
		printf("**** NO RECORS ARE PRESENT ****\n");
		//	return;
			exit(0);
	}
	char op;
	sll *t=ptr;
	FILE *f=fopen("student.data","w");
	printf("   ***** ENTER THE OPTION *****  \n");
	printf("---------------------------------\n");
	printf("| S/s : Save & Exit              |\n");
	printf("| E/e : Exit without saving      |\n");
	printf("---------------------------------\n");
	scanf(" %c",&op);
	if(op>='A'&&op<='Z')
		op+=32;
	switch(op)
	{
		case 's':
			while(t)
			{
				fprintf(f,"%d %s %f\n",t->roll,t->name,t->marks);
				t=t->nxt;
			}
			fclose(f);
			exit(0);
		case 'e':
			exit(0);
		default:
			printf(" **** ENTER THE CORRCT OPTION *****\n");
	}
}

int count(sll *ptr)
{
	int c=0;
	sll *new;
	new=ptr;
	while(new)
	{
		c++;
		new=new->nxt;
	}
	return c;
}
