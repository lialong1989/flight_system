
#ifndef __tASK_H_
#define __tASK_H_

#include "list.h"

struct flight
{
	int num;
	char name[20];
	char time_start[10];
	char time_end[10];
	char addr_start[20];
	char addr_end[20];
	float price;
	struct list_head list;
};






void init_task(void);

int start_task();
void input_task();
void search_task();
void delete_task();
void traversal_task();
void close_task();





#endif
