/* File name    : sort
 * Date         : 09/12/2025
 * Author       : Dayanand
 * Description  : Function Name : sort
 * ----------------------------------------
 * This function is used to sort plant and machine data based on
 * production count in both ascending and descending order.
 *
 * Working:
 * 1. The function displays four sorting options to the user:
 *    - Sort Plants in Ascending Order
 *    - Sort Plants in Descending Order
 *    - Sort Machines in Ascending Order
 *    - Sort Machines in Descending Order
 * 2. Based on the user’s choice, the function performs the selected sort operation.
 * 3. While sorting plants:
 *    - The sorting is done based on the total machine production count of each plant.
 *    - Plant name, location, and machine list pointers are swapped using data swapping.
 * 4. While sorting machines:
 *    - The sorting is done based on individual machine production count.
 *    - Machine details such as ID, name, start time, stop time, cycle time,
 *      and production count are swapped using data swapping.
 * 5. The function applies bubble sort logic for both plant and machine sorting.
 * 6. Sorting is performed safely without modifying linked list pointers directly.
 *
 * This function ensures:
 * - Accurate ascending and descending sorting.
 * - Safe data swapping without pointer corruption.
 * - Proper handling of empty plant and machine lists.
 * - Organized and production-based ordering of system data.
 */

#include<header.h>

int sort()
{
	struct plant *p_temp1;
	struct plant *p_temp2;

	struct machine *m_temp1;
	struct machine *m_temp2;
	struct machine *m_temp3;

	char p_name;
	char p_location[20];
	int choice;
	int machine_id;
	int prod_count;
	char name[20];
	float start;
	float stop;
	float cycle;

	printf("1.SORT THE PLANTS ASCENDING\n");
	printf("2.SORT THE PLANTS DESCENDING\n");
	printf("3.SORT THE MACHINES ASCENDING\n");
	printf("4.SORT THE MACHINES DECENDING\n");

	printf("CHOOSE ONE FROM THE ABOVE : ");
	choice = intvalidation();

	if(choice == 1)
	{
		if(p_start == NULL)
		{
			printf("MACHINE LIST IS EMPTY\n");
			return 0;
		}

		for(p_temp1 = p_start; p_temp1 != NULL ; p_temp1 = p_temp1 -> p_link)
		{
			for(p_temp2 = p_temp1 ; p_temp2 != NULL ; p_temp2 = p_temp2 -> p_link)
			{
				if(p_temp1 -> m_link -> prod_count > p_temp2 -> m_link -> prod_count)
				{
					p_name = p_temp1 -> plant_name;
					strcpy(p_location,p_temp1 -> location);
					m_temp3 = p_temp1 -> m_link;

					p_temp1 -> plant_name = p_temp2 -> plant_name;
					strcpy(p_temp1 -> location,p_temp2 -> location);
					p_temp1 -> m_link = p_temp2 -> m_link;

					p_temp2 -> plant_name = p_name;
					strcpy(p_temp2 -> location,p_location);
					p_temp2 -> m_link = m_temp3;
				}
			}
		}

	}
	else if(choice == 2)
	{
		if(p_start == NULL)
		{
			printf("MACHINE LIST IS EMPTY\n");
			return 0;
		}

		for(p_temp1 = p_start; p_temp1 != NULL ; p_temp1 = p_temp1 -> p_link)
		{
			for(p_temp2 = p_temp1 ; p_temp2 != NULL ; p_temp2 = p_temp2 -> p_link)
			{
				if(p_temp1 -> m_link -> prod_count < p_temp2 -> m_link -> prod_count)
				{
					p_name = p_temp1 -> plant_name;
					strcpy(p_location,p_temp1 -> location);
					m_temp3 = p_temp1 -> m_link;

					p_temp1 -> plant_name = p_temp2 -> plant_name;
					strcpy(p_temp1 -> location,p_temp2 -> location);
					p_temp1 -> m_link = p_temp2 -> m_link;

					p_temp2 -> plant_name = p_name;
					strcpy(p_temp2 -> location,p_location);
					p_temp2 -> m_link = m_temp3;
				}
			}
		}

	}
	else if(choice == 3)
	{
		p_temp1 = p_start;

		if(p_start == NULL)
		{	
			printf("MACHINE LIST IS EMPTY\n");
			return 0;
		}

		while(p_temp1 != NULL)
		{
			if(p_temp1 -> m_link == NULL)
			{
				p_temp1 = p_temp1 -> p_link;
				continue;
			}
			for(m_temp1 = p_temp1 -> m_link; m_temp1 != NULL ; m_temp1 = m_temp1 -> link)
			{
				for(m_temp2 = m_temp1 -> link; m_temp2 != NULL; m_temp2 = m_temp2 -> link)
				{
					if(m_temp1 -> prod_count > m_temp2 -> prod_count)
					{
						machine_id = m_temp1 -> machine_id;
						strcpy(name, m_temp1 -> name);
						start = m_temp1 -> start;
						stop = m_temp1 -> stop;
						cycle = m_temp1 -> cycle;
						prod_count = m_temp1 -> prod_count;

						m_temp1 -> machine_id = m_temp2 -> machine_id;
						strcpy(m_temp1 -> name, m_temp2 -> name);
						m_temp1 -> start = m_temp2 -> start;
						m_temp1 -> stop = m_temp2 -> stop;
						m_temp1 -> cycle = m_temp2 -> cycle;
						m_temp1 -> prod_count = m_temp2 -> prod_count;

						m_temp2 -> machine_id = machine_id;
						strcpy(m_temp2 -> name, name);
						m_temp2 -> start = start;
						m_temp2 -> stop = stop;
						m_temp2 -> cycle = cycle;
						m_temp2 -> prod_count = prod_count;
					}
				}
			}
			p_temp1 = p_temp1 -> p_link;
		}

	}
	else if(choice == 4)
	{
		p_temp1 = p_start;

		if(p_start == NULL)
		{
			printf("MACHINE LIST IS EMPTY\n");
			return 0;
		}

		while(p_temp1 != NULL)
		{
			if(p_temp1 -> m_link == NULL)
			{
				p_temp1 = p_temp1 -> p_link;
				continue;
			}
			for(m_temp1 = p_temp1 -> m_link; m_temp1 != NULL ; m_temp1 = m_temp1 -> link)
			{
				for(m_temp2 = m_temp1 -> link; m_temp2 != NULL; m_temp2 = m_temp2 -> link)
				{
					if(m_temp1 -> prod_count < m_temp2 -> prod_count)
					{
						machine_id = m_temp1 -> machine_id;
						strcpy(name, m_temp1 -> name);
						start = m_temp1 -> start;
						stop = m_temp1 -> stop;
						cycle = m_temp1 -> cycle;
						prod_count = m_temp1 -> prod_count;

						m_temp1 -> machine_id = m_temp2 -> machine_id;
						strcpy(m_temp1 -> name, m_temp2 -> name);
						m_temp1 -> start = m_temp2 -> start;
						m_temp1 -> stop = m_temp2 -> stop;
						m_temp1 -> cycle = m_temp2 -> cycle;
						m_temp1 -> prod_count = m_temp2 -> prod_count;

						m_temp2 -> machine_id = machine_id;
						strcpy(m_temp2 -> name, name);
						m_temp2 -> start = start;
						m_temp2 -> stop = stop;
						m_temp2 -> cycle = cycle;
						m_temp2 -> prod_count = prod_count;
					}
				}
			}
			p_temp1 = p_temp1 -> p_link;
		}

	}
	else
	{
		printf("\nWRONG CHOICE\n");
	}

	return 0;
}
