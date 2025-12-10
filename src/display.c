/* File name    : display
 * Date         : 09/12/2025
 * Author       : Dayanand
 * Description  : Function Name : display
 * ----------------------------------------
 * This function displays all the plant and machine details present
 * in the system in a well-formatted manner.
 *
 * Working:
 * 1. It first checks whether any plants are available in the system.
 *    - If no plants exist, the user is asked whether to add a new plant.
 * 2. The function traverses through the plant linked list.
 * 3. For each plant, it displays:
 *    - Plant Name
 *    - Plant Location
 *    - Total Plant Production Count
 * 4. It then checks whether machines are available under the current plant.
 *    - If no machines exist, the user is prompted to add machines.
 * 5. If machines exist, it traverses the machine linked list and displays:
 *    - Machine ID
 *    - Machine Name
 *    - Machine Start Time
 *    - Machine Stop Time
 *    - Machine Cycle Time
 *    - Machine Production Count
 * 6. The process continues until all plants and their machines are displayed.
 *
 * This function ensures:
 * - Safe traversal of both plant and machine linked lists.
 * - Proper display of hierarchical plant and machine information.
 * - User-friendly formatted output.
 * - Immediate option to add missing plant or machine data.
 */

#include<header.h>

int display()
{
	struct plant *q;
	struct machine *a;
	char choice;


	if(p_start == NULL)
	{
		printf("\nNO PLANTS ARE ADDED! WANT TO ADD Y/N : ");
		choice = charvalidation();

		if(choice == 'Y' || choice == 'y')
		{
			add_plant();
		}
		return 0;
	}

	q = p_start;

	while(q != NULL)
	{
		printf("\n=================== PLANT =======================\n");
		printf("PLANT NAME 		: %c\n",q -> plant_name);
		printf("PLANT LOCATIOn		: %s\n",q -> location);
		printf("PLANT PRODUCTION	: %d\n",q -> plant_prod_count);

		if(q -> m_link == NULL)
		{
			printf("\nNO MACHINES ARE ADDED! WANT TO ADD Y/N : ");
			choice = charvalidation();

			if(choice == 'Y' || choice == 'y')
			{
				add_machine(q -> plant_name);
			}
			return 0;
		}

		a = q -> m_link;

		while(a != NULL)
		{
			printf("\n	=============== MACHINE ==================\n");
			printf("	MACHINE ID 		: %d\n",a -> machine_id);
			printf("	MACHINE NAME 		: %s\n",a -> name);
			printf("	MACHINE START		: %.2f\n",a -> start);
			printf("	MACHINE STOP		: %.2f\n",a -> stop);
			printf("	MACHINE CYCLE TIME(min)	: %.2f\n",a -> cycle);
			printf("	MACHINE PRODUCTION	: %d\n",a -> prod_count);
			a = a -> link;
		}
		q = q -> p_link;
	}
	return 0;
}
