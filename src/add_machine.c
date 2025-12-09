/* File name	: add_machine
 * date		: 09/12/2025
 * Author	: Dayanand
 * description	: Function Name : add_machine
 * ----------------------------------------
 * This function adds a new machine to a selected plant.
 *
 * Working:
 * 1. It first searches for the plant using the plant name.
 * 2. If the plant is not found, it asks the user to add a new plant.
 * 3. It checks for duplicate machine ID inside the selected plant.
 *    - If a duplicate is found, user is asked whether to update the machine.
 * 4. It accepts machine details such as:
 *    - Machine ID
 *    - Machine Name
 *    - Start Time
 *    - Stop Time
 * 5. The start and stop times are converted into minutes using time_min().
 * 6. Machine working duration is calculated correctly even if it crosses midnight.
 * 7. Production cycle count is calculated from duration.
 * 8. The new machine node is linked to the selected plant’s machine list.
 * 9. The total production count of the plant is updated.
 * 10. The user is asked whether to add more machines.
 *
 * This function ensures:
 * - No duplicate machine IDs.
 * - Correct time and production calculations.
 * - Safe insertion into the linked list.
 */

#include<header.h>

int add_machine(char name)
{
	struct plant *q;
	struct machine *p, *temp;


	float duration;
	int choice;
	int found = 0;
	float machine_start;
	float m_stop;
	float m_cycle = 0;
	int total_prod = 0;

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
		printf("\nNO PLANTS ARE ADDED! WANT TO ADD Y/N : ");
		choice = charvalidation();

		if(choice == 'Y' || choice == 'y')
		{
			add_plant();
		}
		return 0;
	}

	p = q -> m_link;

	temp = malloc(sizeof(struct machine));

	printf("\nENTER THE MACHINE ID : ");
	temp -> machine_id = intvalidation();

	while(p != NULL)
	{
		if(p -> machine_id == temp -> machine_id)
		{
			printf("MACINE WITH ID ALREADY EXISTS! DO YOU WANT TO UPDATE THE INPUTS Y/N : ");
			choice = charvalidation();
			if(choice == 'Y' || choice == 'y')
			{
				update_status();
			}
			return 0;
		}
		p = p -> link;
	}

	printf("ENTER THE NAME OF MACHINE : ");
	strcpy(temp -> name, stringvalidation1());

	printf("ENTER THE MACHINE START TIME : ");
	machine_start = floatvalidation();
	temp -> start = machine_start;
	machine_start = time_min(machine_start);

	printf("ENTER THE MACHINE STOP TIME : ");
	m_stop = floatvalidation();
	temp -> stop = m_stop;
	m_stop = time_min(m_stop);

	if(m_stop >= machine_start)
	{
		duration = m_stop - machine_start;
	}
	else
	{
		duration = (24 * 60 - machine_start) + m_stop;
	}

	m_cycle = duration/40;;

	temp -> cycle = duration;
	temp -> prod_count = m_cycle;
	temp -> link = NULL;
	total_prod = total_prod + m_cycle;
	q -> plant_prod_count = total_prod;

	if(q -> m_link == NULL)
	{
		q -> m_link = temp;
	}
	else
	{
		p = q -> m_link;
		while(p -> link != NULL)
			p = p -> link;
		p -> link = temp;
	}
	printf("DO YOU WANT TO ADD MORE MACHINE Y/N : ");
	choice = charvalidation();

	if(choice == 'Y' || choice == 'y')
	{
		add_machine(name);
	}
	return 0;
}


