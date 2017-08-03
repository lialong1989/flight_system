 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "print.h"
#include "task.h"
#include "show.h"

struct list_head head;
struct flight flightinfo;


static void quit_info(void)
{
	printf("退出 q:");
	while('q' != getchar());
}

static int key_get(void)
{
	int key;

	scanf("%d", &key);
	
	return key;
}

static int iscontinue(void)
{
	char ch[2];
	
	printf("是否继续y/n: ");
	scanf("%s", ch);
	
	if (!strncasecmp(ch, "n", 1))
		return 1;
	else
		return 0;
}

void init_task(void)
{
	INIT_LIST_HEAD(&head);
}


int start_task(void)
{
	int num;

	show_startmenu();
	printf(GREEN "选择:" NONE);
	scanf("%d", &num);
	system("clear");

	return num;
}

void input_task(void)
{
	char ch;
	struct flight *new;
	
	system("clear");
	printf("请输入航班信息:\n");
	show_title();
	while (1)
	{
		new = (struct flight *)malloc(sizeof(struct flight));
		if (NULL == new)
		{
			perror("malloc");
			exit(1);
		}
		
		scanf("%d%s%s%s%s%s%f", &new->num, new->name, new->time_start, 
			new->time_end, new->addr_start, new->addr_end, &new->price);
			
		list_add(&new->list, &head);
		
		show_allflight(&head);
		
		if (iscontinue())
			return;
	}	
}

static void search_number(void)
{
	int num, flag = 0;
	struct list_head *pos;
	struct flight *tmp;

	while (1)
	{
		printf("请输入要查询的航班号:");
		scanf("%d", &num);

		show_title();

		list_for_each(pos, &head)
		{
			tmp = list_entry(pos, struct flight, list);
			if (tmp->num == num)
			{
				printf("%d\t%s\t%s\t%s\t%s\t%s\t%.2f\n", tmp->num, tmp->name,
					 tmp->time_start,tmp->time_end, tmp->addr_start, 
					 tmp->addr_end, tmp->price);
				flag = 1;
			}
		}
		
		if (flag)
			flag = 0;
		else
			printf("无此航班\n");
		
		if (iscontinue())
			return;
	}
}

static void search_name(void)
{
	char name[20];
	int flag = 0;
	struct list_head *pos;
	struct flight *tmp;
	
	while (1)
	{
		printf("请输入要查询的航空公司:");
		scanf("%s", name);
		
		show_title();
		
		list_for_each(pos, &head)
		{
			tmp = list_entry(pos, struct flight, list);
			if (!strcmp(tmp->name, name))
			{
				printf("%d\t%s\t%s\t%s\t%s\t%s\t%.2f\n", tmp->num, tmp->name,
					 tmp->time_start,tmp->time_end, tmp->addr_start, 
					 tmp->addr_end, tmp->price);
				flag = 1;
			}
		}
		
		if (flag)
			flag = 0;
		else
			printf("无此航空公司\n");
		
		if (iscontinue())
			return;
	}
}

static void search_time(void)
{
	char time1[10], time2[10];
	int flag = 0;
	struct list_head *pos;
	struct flight *tmp;
	
	while (1)
	{
		printf("请输入要查询的起飞时间段:");
		scanf("%s%s", time1, time2);
		
		show_title();
		
		list_for_each(pos, &head)
		{
			tmp = list_entry(pos, struct flight, list);
			if (((strcmp(tmp->time_start, time1)) >= 0) &&
				((strcmp(tmp->time_start, time2)) <= 0))
			{
				printf("%d\t%s\t%s\t%s\t%s\t%s\t%.2f\n", tmp->num, tmp->name,
					 tmp->time_start,tmp->time_end, tmp->addr_start, 
					 tmp->addr_end, tmp->price);
				flag = 1;
			}
		}
		
		if (flag)
			flag = 0;
		else
			printf("此时间段无航班\n");
		
		if (iscontinue())
			return;
	}
}

static void search_addr(void)
{
	char addr1[20], addr2[20];
	int flag = 0;
	struct list_head *pos;
	struct flight *tmp;
	
	while (1)
	{
		printf("请输入要查询的出发目的地:");
		scanf("%s%s", addr1, addr2);
		
		show_title();
		
		list_for_each(pos, &head)
		{
			tmp = list_entry(pos, struct flight, list);
			if (((strcmp(tmp->addr_start, addr1)) == 0) &&
				((strcmp(tmp->addr_end, addr2)) == 0))
			{
				printf("%d\t%s\t%s\t%s\t%s\t%s\t%.2f\n", tmp->num, tmp->name,
					 tmp->time_start,tmp->time_end, tmp->addr_start, 
					 tmp->addr_end, tmp->price);
				flag = 1;
			}
		}
		
		if (flag)
			flag = 0;
		else
			printf("此地点区间无航班\n");
		
		if (iscontinue())
			return;
	}
}

static void search_price(void)
{
	float price1, price2;
	int flag = 0;
	struct list_head *pos;
	struct flight *tmp;
	
	while (1)
	{
		printf("请输入要查询的价格区间:");
		scanf("%f%f", &price1, &price2);
		
		show_title();
		
		list_for_each(pos, &head)
		{
			tmp = list_entry(pos, struct flight, list);
			if ((tmp->price >= price1) && (tmp->price <= price2))
			{
				printf("%d\t%s\t%s\t%s\t%s\t%s\t%.2f\n", tmp->num, tmp->name,
					 tmp->time_start,tmp->time_end, tmp->addr_start, 
					 tmp->addr_end, tmp->price);
				flag = 1;
			}
		}
		
		if (flag)
			flag = 0;
		else
			printf("此价格区间无航班\n");
		
		if (iscontinue())
			return;
	}
}

void search_task(void)
{
	while (1)
	{
		show_search();
		
		printf("选择查找条件:");
		
		switch (key_get())
		{
			case 1:
				search_number();
				break;
			case 2:
				search_name();
				break;
			case 3:
				search_time();
				break;
			case 4:
				search_addr();
				break;
			case 5:
				search_price();
				break;
			case 6:
				return;
			default:
				printf("输入错误,请重新输入\n");
				break;
		}
	}
}

void delete_task(void)
{
	int num;
	int flag = 0;
	struct list_head *pos;
	struct list_head *pos_tmp;
	struct flight *tmp;
	
	while (1)
	{
		show_title();
		show_allflight(&head);
		printf("请输入删除的航班号:");
		scanf("%d", &num);
		
		list_for_each(pos, &head)
		{
			tmp = list_entry(pos, struct flight, list);
			if (tmp->num == num)
			{
				pos_tmp = pos->prev;
				list_del(&(tmp->list));
				pos = pos_tmp;
				free(tmp);
				
				show_title();
				show_allflight(&head);
		
				flag = 1;
			}
		}
		
		if (flag)
			flag = 0;
		else
			printf("无此航班\n");
		
		if (iscontinue())
			return;
	}
}

void traversal_task(void)
{
	show_allflight(&head);

	quit_info();
}

void close_task(void)
{
	struct list_head *pos;
	struct flight *tmp;
	
	list_for_each(pos, &head)
	{
		tmp = list_entry(pos, struct flight, list); 
		free(tmp);
	}
	
	show_closesystem();
	exit(0);
}

