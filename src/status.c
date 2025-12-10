/* File name    : status
 * Date         : 09/12/2025
 * Author       : Dayanand
 * Description  : Function Name : status
 * ----------------------------------------
 * This function displays the status of plants and machines based on
 * different user-selected criteria.
 *
 * Working:
 * The function provides three options:
 *
 * 1. View status of ALL plants:
 *    - Calls the display() function to print every plant and machine.
 *
 * 2. View status of a particular plant:
 *    - Prompts the user to enter a plant name.
 *    - Searches for the plant in the plant linked list.
 *    - If found:
 *          • Displays plant name and location.
 *          • Displays the status of all machines under that plant.
 *      If plant does not exist, an error message is shown.
 *
 * 3. View status of a particular machine:
 *    - Prompts for both plant name and machine ID.
 *    - Searches for the plant first.
 *    - Then searches the machine inside that plant.
 *    - If found, the machine details (ID, Name, Start, Stop, Cycle, Production)
 *      are displayed.
 *    - If plant or machine does not exist, an error message is shown.
 *
 * This function ensures:
 * - Clear and hierarchical representation of plant and machine data.
 * - Safe traversal of linked lists.
 * - Proper validation of plant and machine existence.
 * - Easy debugging and monitoring of system status.
 */

#include<header.h>

int status()
{
	struct plant *q;
	struct machine *a;

	int choice;
	int id;
	char name;
	int p_found = 0;
	int m_found = 0;

	printf("\n=========================================\n");
	printf("| 1. | VIEW STATUS OF ALL PLANT		|\n");
	printf("|----|----------------------------------|\n");
	printf("| 2. | VIEW STATUS OF PERTICULAR PLANT	|\n");
	printf("|----|----------------------------------|\n");
	printf("| 3. | VIEW STATUS OF PERTICULAR MACHINE|\n");
	printf("=========================================\n");

	printf("\nCHOOSE ONE FROM THE ABOVE : ");
	choice = intvalidation();


	if(choice == 1)
	{
		display();
	}
	else if(choice == 2)
	{
		printf("\nENTER THE PLANT NAME : ");
		name = charvalidation();

		q = p_start;

		while(q != NULL)
		{printf("|----|----------------------------------|\n");
			if(q -> plant_name == name)
			{
				p_found = 1;
				break;
			}
			q = q -> p_link;
		}
		if(p_found != 1)
		{
			printf("\n-----***** PLANT DOES NOT EXISTS *****-----\n");
			return 0;
		}

		q = p_start;
		while(q != NULL)
		{
			if(q -> plant_name == name)
			{
				printf("\n================= PLANT %c ==================\n",q -> plant_name);
				printf("PLANT NAME		: %c\n",q -> plant_name);
				printf("LOCATION OF PLANT	: %s\n",q -> location);

				if(q -> m_link == NULL)
				{
					printf("\n-----***** NO MACHINES ARE ADDED *****-----\n");
					return 0;
				}

				a = q -> m_link;

				while(a != NULL)
				{
					printf("\n	================== MACHINE ==================\n");
					printf("	MACHINE ID              : %d\n",a -> machine_id);
					printf("	MACHINE NAME            : %s\n",a -> name);
					printf("	MACHINE START           : %.2f\n",a -> start);
					printf("	MACHINE STOP            : %.2f\n",a -> stop);
					printf("	MACHINE CYCLE TIME(min) : %.2f\n",a -> cycle);
					printf("	MACHINE PRODUCTION      : %d\n",a -> prod_count);
					a = a -> link;
				}
			}
			q = q -> p_link;
		}
	}
	else if(choice == 3)
	{
		printf("ENTER THE PLANT NAME : ");
		name = charvalidation();

		q = p_start;

		while(q != NULL)
		{
			if(q -> plant_name == name)
			{
				p_found = 1;
				break;
			}
			q = q -> p_link;
		}
		if(p_found != 1)
		{
			printf("\n-----***** PLANT DOES NOT EXISTS *****-----\n");
			return 0;
		}

		printf("ENTER THE MACHINE ID : ");
		id = intvalidation();

		q = p_start;
		while(q != NULL)
		{
			if(q -> plant_name == name)
			{
				printf("\n================= PLANT %c ==================\n",q -> plant_name);
				printf("PLANT NAME              : %c\n",q -> plant_name);
				printf("LOCATION OF PLANT       : %s\n",q -> location);

				if(q -> m_link == NULL)
				{
					printf("\n-----***** NO MACHINES ARE ADDED *****-----\n");
					return 0;
				}

				a = q -> m_link;
				while(a != NULL)
				{
					if(a -> machine_id == id)
					{
						m_found = 1;
						printf("\n	==================== MACHINE ==================\n");
						printf("	MACHINE ID              : %d\n",a -> machine_id);
						printf("	MACHINE NAME            : %s\n",a -> name);
						printf("	MACHINE START           : %.2f\n",a -> start);
						printf("	MACHINE STOP            : %.2f\n",a -> stop);
						printf("	MACHINE CYCLE TIME(min) : %.2f\n",a -> cycle);
						printf("	MACHINE PRODUCTION      : %d\n",a -> prod_count);
						break;
					}
					a = a -> link;
				}
				if(m_found != 1)
				{
					printf("\n-----***** MACHINE DOES NOT EXISTS IN PLANT *****-----\n");
					return 0;
				}
			}
			q = q -> p_link;
		}
	}
	else
	{
		printf("\n-----***** WRONG CHOICE *****-----\n");
	}
	return 0;
}
