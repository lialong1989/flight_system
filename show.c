
#include <stdio.h>

#include "show.h"
#include "print.h"
#include "task.h"

void show_title(void)
{
	printf(RED "航班号\t航空公司\t起飞时间\t到达时间\t出发地\t目的地\t价格" NONE "\n");
}

void show_startmenu(void)
{
	system("clear");
	printf("\n\t\t\t");
	printf(BLUE "***************************************");
	printf("\n\t\t\t");
	printf(RED "|** 1.录入航班信息  2.查询航班信息  **|");
	printf("\n\t\t\t");
	printf(RED "|** 3.删除航班信息  4.显示航班信息  **|");
	printf("\n\t\t\t");
	printf(RED "|** 5.关机                          **|");
	printf("\n\t\t\t");
	printf(BLUE "***************************************");
	printf(NONE "\n");
}

void show_closesystem(void)
{
	system("clear");
	printf("\n\t\t\t");
	printf(GREEN " shutdown flight system......");
	printf("\n\t\t\t");
	sleep(1);
	printf(RED "******************************");
	printf("\n\t\t\t");
	sleep(1);
	printf(GREEN "******************************");
	printf("\n\t\t\t");
	sleep(1);
	printf(YELLOW "******************************");
	printf(NONE "\n");
	sleep(1);
}

void show_search(void)
{
	system("clear");
	printf("\n\t\t\t");
	printf(BLUE "**********************************");
	printf("\n\t\t\t");
	printf(RED "1.航班号      2.航空公司  3.时间段");
	printf("\n\t\t\t");
	printf(RED "4.出发目的地  5.价格      6.退出");
	printf("\n\t\t\t");
	printf(BLUE "**********************************");
	printf(NONE "\n");
}

void show_allflight(struct list_head *head)
{
	struct list_head *pos;
	struct flight *tmp;
	
	system("clear");
	show_title();
	
	list_for_each(pos, head)
	{
		tmp = list_entry(pos, struct flight, list); 
		printf("%d\t%s\t%s\t%s\t%s\t%s\t%.2f\n", tmp->num, tmp->name, tmp->time_start, 
			tmp->time_end, tmp->addr_start, tmp->addr_end, tmp->price);
	}
}
