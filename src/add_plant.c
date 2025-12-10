/* File name    : add_plant
 * Date         : 09/12/2025
 * Author       : Dayanand
 * Description  : Function Name : add_plant
 * ----------------------------------------
 * This function creates and adds a new plant to the plant linked list.
 *
 * Working:
 * 1. It prompts the user to enter a plant name.
 * 2. It checks whether a plant with the same name already exists.
 *    - If the plant already exists, the user is asked whether to add a machine.
 * 3. If the plant does not exist, the user is prompted to enter the plant location.
 * 4. A new plant node is dynamically allocated using malloc().
 * 5. The plant details such as:
 *    - Plant Name
 *    - Plant Location
 *    - Initial Production Count (set to 0)
 *    are stored in the structure.
 * 6. The new plant is inserted at the end of the plant linked list.
 * 7. After adding the plant, the function automatically calls add_machine()
 *    to allow the user to add machines to the newly created plant.
 *
 * This function ensures:
 * - No duplicate plant names are allowed.
 * - Proper dynamic memory allocation.
 * - Safe insertion into the plant linked list.
 * - Automatic machine addition functionality.
 */

#include<header.h>

int add_plant()
{
	struct plant *q;
	struct plant *temp;
	char name;
	char loc[20];
	char choice;

	printf("\nENTER THE PLANT NAME (A, B, etc) : ");
	name = charvalidation();

	q = p_start;
	while(q != NULL)
	{
		if(q -> plant_name == name)
		{
			printf("\nPLANT ALREADY EXISTS WANT TO ADD MACHINE Y/N : ");
			choice = charvalidation();
			if(choice == 'Y' || choice == 'y')
			{
				add_machine(name);
			}
			return 0;
		}
		q = q -> p_link;
	}

	printf("ENTER THE LOCATION OF PLANT : ");
	strcpy(loc,stringvalidation1());

	temp = malloc(sizeof(struct plant));
	temp -> plant_name = name;
	strcpy(temp -> location,loc);
	temp -> plant_prod_count = 0;
	temp -> p_link = NULL;
	temp -> m_link = NULL;

	if(p_start == NULL)
	{
		p_start = temp;
		printf("\n-----***** PLANT ADDED SUCCESSFULLY *****-----\n");
		add_machine(name);
	}
	else
	{
		q = p_start;
		while(q -> p_link != NULL)
			q = q -> p_link;
		q -> p_link = temp;
		printf("\n-----***** PLANT ADDED SUCCESSFULLY *****-----\n");

		add_machine(name);
	}
	return 0;
}
