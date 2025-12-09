/* File name    : update_status
 * Date         : 09/12/2025
 * Author       : Dayanand
 * Description  : Function Name : update_status
 * ----------------------------------------
 * This function updates the working status of a specific machine
 * inside a selected plant by modifying its start and stop time.
 *
 * Working:
 * 1. The function prompts the user to enter the plant name.
 * 2. It searches for the plant in the plant linked list.
 *    - If the plant does not exist, an error message is displayed.
 * 3. It checks whether any machines are available in the selected plant.
 *    - If no machines exist, an appropriate message is displayed.
 * 4. The user is prompted to enter the machine ID to be updated.
 * 5. If the first machine matches the entered ID:
 *    - The new start and stop time values are accepted.
 *    - The time values are converted into minutes using time_min().
 *    - The new working duration is calculated (including midnight crossing).
 *    - The machine cycle time and production count are updated.
 * 6. Otherwise, the function traverses through the remaining machine list:
 *    - If the matching machine is found, its timing and production values
 *      are updated using the same calculation logic.
 * 7. A success message is displayed after successful update.
 *
 * This function ensures:
 * - Accurate update of machine working time and production count.
 * - Proper handling of time conversion and midnight crossover.
 * - Safe traversal of machine linked lists.
 * - Error-free update of only the selected machine.
 */

#include<header.h>

int update_status()
{
	struct plant *q;
	struct machine *m;
	char name;
	int found = 0;
	int id;
	int machine_start;
	int machine_stop;
	int duration;
	float m_cycle;

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
		printf("\nENTER THE STAR TIME OF THE MACHINE : ");
		machine_start = floatvalidation();
		q -> m_link -> start = machine_start;
		machine_start = time_min(machine_start);

		printf("ENTER THE STOP TIME OF THE MACHINE : ");
		machine_stop = floatvalidation();
		q -> m_link -> stop = machine_stop;
		machine_stop = time_min(machine_stop);

		if(machine_stop >= machine_start)
		{
			duration = machine_stop - machine_start;
		}
		else
		{
			duration = (24 * 60 - machine_start) + machine_stop;
		}

		m_cycle = duration/40;

		q -> m_link -> cycle = duration;
		q -> m_link -> prod_count = m_cycle;

		printf("\n-----***** MACHINE DETAILS UPDATED SUCCESSFULLY *****-----\n");
		return 0;
	}
	m = q -> m_link;

	while(m -> link != NULL)
	{
		if(m -> link -> machine_id == id)
		{
			printf("\nENTER THE STAR TIME OF THE MACHINE : ");
			machine_start = floatvalidation();
			m -> link -> start = machine_start;
			machine_start = time_min(machine_start);

			printf("ENTER THE STOP TIME OF THE MACHINE : ");
			machine_stop = floatvalidation();
			m -> link -> stop = machine_stop;
			machine_stop = time_min(machine_stop);

			if(machine_stop >= machine_start)
			{
				duration = machine_stop - machine_start;
			}
			else
			{
				duration = (24 * 60 - machine_start) + machine_stop;
			}

			m_cycle = duration/40;

			m -> link -> cycle = duration;
			m -> link -> prod_count = m_cycle;

			printf("\n-----***** MACHINE DETAILS UPDATED SUCCESSFULLY *****-----\n");
			return 0;

		}
		m = m -> link;
	}
	return 0;
}
