#ifndef STUDENT_H
#define STUDENT_H

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

typedef struct stu{
	int roll;
	char name[20];
	float marks;
	struct stu *nxt;
}sll;

void add_new(sll **);
void show_list(sll *);
void save(sll *);
void exit_list(sll *);
void delete_all(sll **);
void modify(sll **);
void delete_a_node(sll **);
void sort_list(sll *);
int count(sll *);
void reverse_list(sll **);
void load_list(sll **);

#endif
