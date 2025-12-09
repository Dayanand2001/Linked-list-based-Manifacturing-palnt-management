#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"validation.h"

struct machine {
	int machine_id;
	char name[20];
	float start;
	float stop;
	float cycle;
	int prod_count;
	struct machine *link;
};	
struct plant {
	char plant_name;
	char location[15];
	int plant_prod_count;
	struct plant *p_link;
	struct machine *m_link;
};

extern struct machine *m_start;
extern struct plant *p_start;
extern int count;
extern int count1;

int create_plant();
int add_plant();
int deletre_plant();
int add_machine(char name);
int delete_machine();
int update_status();
int display();
int time_min(float time);
int status();
int sort();
int search();
