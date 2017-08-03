
#include <stdio.h>

#include "task.h"

int main(void)
{
	init_task();
	
	while (1)
	{
		switch (start_task())
		{
			case 1:
				input_task();
				break;
			case 2:
				search_task();
				break;
			case 3:
				delete_task();
				break;
			case 4:
				traversal_task();
				break;
			case 5:
				close_task();
				break;
			default:
				break;
		}
	}



	return 0;
}
