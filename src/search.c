/* File name    : search
 * Date         : 09/12/2025
 * Author       : Dayanand
 * Description  : Function Name : search
 * ----------------------------------------
 * This function is used to search plant and machine information
 * based on user-selected criteria.
 *
 * Working:
 * 1. The function displays two search options:
 *    - Search by Plant Name
 *    - Search by Machine ID
 * 2. If the user selects search by plant name:
 *    - The function searches for the plant in the plant linked list.
 *    - If found, it displays the plant details and all its machine details.
 *    - If not found, it displays an appropriate error message.
 * 3. If the user selects search by machine ID:
 *    - The user is prompted to enter the plant name and machine ID.
 *    - The function searches the specified plant first.
 *    - Then it searches for the machine inside that plant.
 *    - If found, both plant and machine details are displayed.
 * 4. Proper validation is done to ensure correct search results.
 *
 * This function ensures:
 * - Fast and accurate searching of plants and machines.
 * - Clear and formatted display of search results.
 * - Safe traversal of plant and machine linked lists.
 * - Proper handling of invalid plant or machine references.
 */

#include<header.h>

int search()
{
	struct plant *p;
	struct machine *m;

	int choice;
	char name;
	int id;
	int p_found = 0;
	int m_found = 0;

	printf("\n=================================\n");
	printf("| 1. | SEARCH BY PLANT NAME	|\n");
	printf("|----|--------------------------|\n");
	printf("| 2. | SEARCH BY MACHINE ID	|\n");
	printf("=================================\n");

	printf("\nCHOOSE ONE FROM THE ABOVE : ");
	choice = intvalidation();

	if(choice == 1)
	{
		printf("\nENTER THE PLANT NAME (A, B, C or etc) : ");
		name = charvalidation();

		p = p_start;

		while(p != NULL)
		{
			if(p -> plant_name == name)
			{
				p_found = 1;
				printf("\n=================== PLANT =======================\n");
				printf("PLANT NAME              : %c\n",p -> plant_name);
				printf("PLANT LOCATIOn          : %s\n",p -> location);
				printf("PLANT PRODUCTION        : %d\n",p -> plant_prod_count);

				m = p -> m_link;

				while(m != NULL)
				{
					printf("\n	=============== MACHINE ==================\n");
					printf("	MACHINE ID              : %d\n",m -> machine_id);
					printf("	MACHINE NAME            : %s\n",m -> name);
					printf("	MACHINE START           : %.2f\n",m -> start);
					printf("	MACHINE STOP            : %.2f\n",m -> stop);
					printf("	MACHINE CYCLE TIME(min) : %.2f\n",m -> cycle);
					printf("	MACHINE PRODUCTION      : %d\n",m -> prod_count);
					m = m -> link;
				}
				return 0;
			}
			p = p -> p_link;
		}
		if(p_found != 1)
		{
			printf("\n-----***** PLANT DOES NOT EXISTS *****-----\n");
			return 0;
		}
	}
	else if(choice == 2)
	{
		printf("ENTER THE PLANT NAME : ");
		name = charvalidation();

		printf("ENTER THE MACHINE ID : ");
		id = intvalidation();

		p = p_start;

		while(p != NULL)
		{
			if(p -> plant_name == name)
			{
				p_found = 1;
				m = p -> m_link;
				while(m != NULL)
				{
					if(m -> machine_id == id)
					{
						m_found = 1;
						printf("\n=================== PLANT =======================\n");
						printf("PLANT NAME              : %c\n",p -> plant_name);
						printf("PLANT LOCATIOn          : %s\n",p -> location);
						printf("PLANT PRODUCTION        : %d\n",p -> plant_prod_count);

						printf("\n	=============== MACHINE ==================\n");
						printf("	MACHINE ID              : %d\n",m -> machine_id);
						printf("	MACHINE NAME            : %s\n",m -> name);
						printf("	MACHINE START           : %.2f\n",m -> start);
						printf("	MACHINE STOP            : %.2f\n",m -> stop);
						printf("	MACHINE CYCLE TIME(min) : %.2f\n",m -> cycle);
						printf("	MACHINE PRODUCTION      : %d\n",m -> prod_count);
						return 0;
					}
					m = m -> link;
				}
			}
			p = p -> p_link;
		}
		if(p_found != 1)
		{
			printf("\n-----***** PLANT DOES NOT EXISTS *****-----\n");
			return 0;
		}
		if(m_found != 1)
		{
			printf("\n-----***** MACHINE DOES NOT EXISTS *****-----\n");
			return 0;
		}
	}
	else
	{
		printf("\n-----***** WRONG CHOICE *****-----\n");
	}
	return 0;
}

