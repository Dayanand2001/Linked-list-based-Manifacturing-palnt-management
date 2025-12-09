/* File name    : delete_plant
 * Date         : 09/12/2025
 * Author       : Dayanand
 * Description  : Function Name : delete_plant
 * ----------------------------------------
 * This function deletes a plant from the plant linked list based on
 * the plant name and location entered by the user.
 *
 * Working:
 * 1. It first checks whether any plants exist in the system.
 *    - If no plants exist, the user is asked whether to add a new plant.
 * 2. The user is prompted to enter:
 *    - Plant Name
 *    - Plant Location
 * 3. If the first plant in the linked list matches the given name and location:
 *    - The first plant node is deleted.
 * 4. Otherwise, the function traverses the plant linked list:
 *    - If a matching plant is found in the middle or at the end of the list,
 *      that plant node is deleted safely.
 * 5. Memory allocated for the deleted plant is freed using free().
 * 6. A success message is displayed after successful deletion.
 * 7. If the plant is not found, an appropriate error message is shown.
 *
 * This function ensures:
 * - Safe deletion of first, middle, and last plant nodes.
 * - Proper validation of plant existence.
 * - No memory leaks after deletion.
 * - Clean maintenance of the plant linked list structure.
 */

#include<header.h>

int deletre_plant()
{
	struct plant *q, *temp;
	char name;
	char loc[20];
	char choice;
	int found = 0;

	if(p_start == NULL)
	{
		printf("NO PLANT IS ADDED! WANT TO ADD PLANT Y/N : ");
		choice = charvalidation();
		if(choice == 'Y' || choice == 'y')
		{
			add_plant();
			return 0;
		}
		return 0;
	}

	printf("ENTER THE NAME OF PLANT TO DELET : ");
	name = charvalidation();

	printf("ENTER THE LOCATION OF PLANT : ");
	strcpy(loc,stringvalidation1());

	if(p_start -> plant_name == name && strcmp(p_start -> location,loc) == 0)
	{
		found = 1;
		temp = p_start;
		p_start = p_start -> p_link;
		free(temp);

		printf("PLANT DELETED SUCCESSFULLY.\n");

		return 0;
	}
	q = p_start;

	while(q -> p_link != NULL)
	{
		if(q -> p_link -> plant_name == name && strcmp(q -> p_link -> location,loc)==0)
		{
			found = 1;
			temp = q -> p_link;
			q -> p_link = temp -> p_link;
			free(temp);

			printf("PLANT DELETED SUCCESSFULLY.\n");
			return 0;
		}
		q = q -> p_link;
	}
	if(found != 1)
	{
		printf("-----*****PLANT DOES NOT EXISTS*****-----\n");
	}
	return 0;
}

