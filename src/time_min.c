/* File name    : time_min
 * Date         : 09/12/2025
 * Author       : Dayanand
 * Description  : Function Name : time_min
 * ----------------------------------------
 * This function converts time given in HH.MM format into total minutes.
 *
 * Working:
 * 1. The input time is received in float format (example: 10.30).
 * 2. The integer part of the value is extracted as hours.
 * 3. The decimal part is extracted and converted into minutes.
 * 4. The total minutes are calculated using:
 *      total_minutes = (hours × 60) + minutes
 * 5. The calculated total minutes value is returned to the caller.
 *
 * This function ensures:
 * - Accurate conversion of time from HH.MM format to minutes.
 * - Easy calculation of machine working duration.
 * - Support for time difference calculations across midnight.
 * - Clean and reliable time processing for production calculations.
 */

#include<header.h>

int time_min(float time)
{
        int hour;
        int min;
        int total_min;

        hour = (int)time;
        min = (int)((time - hour)*100);
        total_min = (hour*60) + min;

        return total_min;
}
