/* File name    : create_plant
 * Date         : 09/12/2025
 * Author       : Dayanand
 * Description  : Function Name : create_plant
 * ----------------------------------------
 * This function acts as the main menu-driven control function of the project.
 * It continuously displays the list of available operations and allows the
 * user to perform different actions related to plants and machines.
 *
 * Working:
 * 1. Displays a formatted menu with all available operations.
 * 2. Accepts the user’s choice using validated integer input.
 * 3. Based on the selected option, it performs the following actions:
 *    - Add a new plant.
 *    - Delete an existing plant.
 *    - Add machines to a selected plant.
 *    - Delete a machine from a selected plant.
 *    - Update machine details.
 *    - View plant and machine status.
 *    - Sort plants or machines.
 *    - Search for a plant or machine.
 *    - Exit the application.
 * 4. The function runs inside an infinite loop to keep the program active
 *    until the user explicitly chooses to exit.
 *
 * This function ensures:
 * - Continuous interaction with the user.
 * - Centralized control for all system operations.
 * - Proper input validation for menu selection.
 * - Safe execution of plant and machine operations.
 */

#include<header.h>

int create_plant()
{
	int choice;
	char p_name;

	while(1)
	{
		printf("\n=================================\n");
		printf("|SL.NO	| OPREATIONS		|\n");
		printf("|-------|-----------------------|\n");
		printf("|  1.	| ADD PLANT		|\n");
		printf("|-------|-----------------------|\n");
		printf("|  2.	| DELETE PLANT		|\n");
		printf("|-------|-----------------------|\n");
		printf("|  3.	| ADD MACHINES		|\n");
		printf("|-------|-----------------------|\n");
		printf("|  4.	| DELETE MACHINE	|\n");
		printf("|-------|-----------------------|\n");
		printf("|  5.	| MACHINE UPDATES	|\n");
		printf("|-------|-----------------------|\n");
		printf("|  6.	| VIEW STATUS		|\n");
		printf("|-------|-----------------------|\n");
		printf("|  7.   | SORT                  |\n");
		printf("|-------|-----------------------|\n");
		printf("|  8.   | SEARCH                |\n");
		printf("|-------|-----------------------|\n");
		printf("|  9.	| EXIT			|\n");
		printf("=================================\n");

		printf("\nCHOOSE ONE FROM THE ABOVE : ");
		choice = intvalidation();

		switch(choice)
		{
			case 1:
				add_plant();
				break;
			case 2:
				deletre_plant();
				break;
			case 3:
				printf("\nENTER THE PLANT NAME : ");
				p_name = charvalidation();
				add_machine(p_name);
				break;
			case 4:
				delete_machine();
				break;
			case 5:
				update_status();
				break;
			case 6: 
				status();
				break;
			case 7:
				sort();
				break;
			case 8:
				search();
				break;
			case 9:
				exit(1);
			default:
				printf("\n-----*****INVALID CHOICE*****-----\n");
		}
	}
	return 0;
}
