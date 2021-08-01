/**
 * @file activity1.c
 * @author SingarajuAmulya
 * @brief LED on if Seat Occupied and Heater is ON
 * @version 0.1
 * @date 2021-08-01
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <avr/io.h>
#include <util/delay.h>
#include "activity1.h"

/**
 * @brief Port Assignments
 *
 */
void port_assignment()
{
    DDRD&=~(1<<heater);
    DDRD&=~(1<<seat);


    PORTD|=(1<<heater);
    PORTD|=(1<<seat);


    DDRB|=(1<<LED);//output LED
}
/**
 * @brief Activity1 definition for LED ON Condition
 *
 * @return int
 */
int activity1(void)
{

port_assignment();//Calling port assignments

while(1)
{
/**
 * @brief Construct a new if object of LED ON if
 *
 * @param heater_switch_close and @param seat_switch_close is met
 */
if((heater_switch_close) && (seat_switch_close)) //if both switches CLOSE
{
    PORTB|=(1<<LED);//LED ON
    _delay_ms(100);
}


/**
 * @brief else LED OFF
 *
 */
else
{
    PORTB&=~(1<<LED);//LED OFF
    _delay_ms(100);
}


}

return 0;
}
