/* File name    : delete_machine
 * Date         : 09/12/2025
 * Author       : Dayanand
 * Description  : Function Name : delete_machine
 * ----------------------------------------
 * This function deletes a machine from a selected plant based on the machine ID.
 *
 * Working:
 * 1. It prompts the user to enter the plant name.
 * 2. It searches for the plant in the plant linked list.
 *    - If the plant does not exist, an error message is displayed.
 * 3. It checks whether any machines are present in the selected plant.
 *    - If no machines exist, an appropriate message is displayed.
 * 4. The user is prompted to enter the machine ID to be deleted.
 * 5. If the first machine matches the entered ID:
 *    - The first node is deleted and the machine list head is updated.
 * 6. Otherwise, the function traverses through the remaining machine list:
 *    - If a matching machine ID is found, that machine node is deleted safely.
 * 7. Memory allocated for the deleted machine is freed using free().
 *
 * This function ensures:
 * - Safe deletion of machine nodes.
 * - Proper handling of first, middle, and last machine nodes.
 * - No memory leaks.
 * - Accurate validation of plant and machine existence.
 */

#include<header.h>

int delete_machine()
{
	struct plant *q; 
	struct machine *m, *temp;
	char name;
	int found = 0;
	int id;

	printf("ENTER THE PLANT NAME : ");
	name = charvalidation();

	q = p_start;

	while(q != NULL)
	{
		if(q -> plant_name == name)
		{
			found = 1;
			break;
		}
		q = q -> p_link;
	}

	if(found != 1)
	{
		printf("\n-----*****PLANT DOES NOT EXISTS*****-----\n");
		return 0;
	}

	if(q->m_link == NULL)
	{
		printf("\n-----***** NO MACHINES IN THIS PLANT *****-----\n");
		return 0;
	}

	printf("ENTER  THE MACHINE ID : ");
	id = intvalidation();

	if(q -> m_link -> machine_id == id)
	{
		temp = q -> m_link;
		q -> m_link = q -> m_link -> link;
		free(temp);
		printf("\n-----***** MACHINE DELETED SUCCESSFULLY *****-----\n");
		return 0;
	}

	m = q -> m_link;

	while(m -> link != NULL)
	{
		if(m -> link -> machine_id == id)
		{
			temp = m -> link;
			m -> link = temp -> link;
			free(temp);
			printf("\n-----***** MACHINE DELETED SUCCESSFULLY *****-----\n");
			return 0;
		}
		m = m -> link;
	}
	return 0;
}
